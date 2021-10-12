CC = gcc

ODIR = bin

cJSON_CFLAGS = -I3rdparty/cJSON
cJSON_OBJ = 3rdparty/cJSON/cJSON_min.o

secp256k1_DEFS = \
	-DUSE_NUM_NONE=1 \
	-DUSE_FIELD_INV_BUILTIN=1 \
	-DUSE_SCALAR_INV_BUILTIN=1 \
	-DECMULT_WINDOW_SIZE=2 \
	-DECMULT_GEN_PREC_BITS=2 \
	-DENABLE_MODULE_RECOVERY \
	-DUSE_ECMULT_STATIC_PRECOMPUTATION \
	-DUSE_FORCE_WIDEMUL_INT64
secp256k1_CFLAGS = -I3rdparty/secp256k1 -I3rdparty/secp256k1/include
secp256k1_OBJ = 3rdparty/secp256k1/src/secp256k1.o

bns_client_CFLAGS = $(cJSON_CFLAGS) $(secp256k1_CFLAGS) -Isrc 
bns_client_OBJ = $(cJSON_OBJ) $(secp256k1_OBJ) \
	src/bns-client/contract/clearance_record_cache.o \
	src/bns-client/contract/contract.o \
	src/bns-client/core/bns_exit_code.o \
	src/bns-client/input/binary_ledger_input.o \
	src/bns-client/input/ledger_input.o \
	src/bns-client/input/ledger_input_request.o \
	src/bns-client/input/receipt.o \
	src/bns-client/input/receipt_locator.o \
	src/bns-client/register/register.o \
	src/bns-client/register/bns_server_info.o \
	src/bns-client/sha256/sha256.o \
	src/bns-client/util/crypto/keccak256.o \
	src/bns-client/util/byte_util.o \
	src/bns-client/util/log.o \
	src/bns-client/util/numeric_util.o \
	src/bns-client/util/signature_util.o \
	src/bns-client/util/slice_validation_util.o \
	src/bns-client/util/string_util.o \
	src/bns-client/util/time_util.o \
	src/bns-client/verify/merkle_proof.o \
	src/bns-client/verify/slice.o \
	src/bns-client/verify/verify.o \
	src/bns-client/verify/verify_receipt_result.o \
	src/bns-client/bns_client.o

%.o: %.c
	@echo "Building C object $@"
	@$(CC) -c -o $@ $< $(bns_client_CFLAGS) $(secp256k1_DEFS)

.PHONY: all
all: bns-client-example

# bns-client-example
bns_client_example_CFLAGS = $(bns_client_CFLAGS) -lcurl
bns_client_example_OBJ = $(bns_client_OBJ) \
	example/bns-client-example/bns_client_example.o \
	example/bns-client-example/callback.o \
	example/bns-client-example/receipt_dao.o \
	example/bns-client-example/ssl_get.o

bns-client-example: $(bns_client_example_OBJ)
	@mkdir -p $(ODIR)
	@echo "Building C executable $@"
	@$(CC) -o $(ODIR)/$@ $^ $(bns_client_example_CFLAGS) $(secp256k1_DEFS)  -Iexample/bns-client-example
	@echo "Built target $@"

.PHONY: clean
clean:
	@rm -f $(bns_client_example_OBJ)
	@rm -rf $(ODIR)

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... bns-client-example"
.PHONY : help
