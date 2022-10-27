BUILD_DIR = ./build
LIB_DIR = ./lib
DEST_DIR = ./out
DEST_EXE_NAME = sms

all: build
	cd $(BUILD_DIR); make -j4

build:
	mkdir $(BUILD_DIR); cd $(BUILD_DIR); cmake ..

run:
	cd $(DEST_DIR); ./$(DEST_EXE_NAME)

clean:
	rm $(BUILD_DIR) -rf

cleanall:
	rm $(DEST_DIR) $(BUILD_DIR)  $(LIB_DIR) -rf
