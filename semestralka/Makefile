TARGET = hrubate1
CXX = g++
CXX_FLAGS = -Wall -pedantic -Wextra -std=c++14

MKDIR = mkdir -p
BUILD_DIR = build

.PHONY: all
all: compile

.PHONY: compile
compile: $(TARGET)

.PHONY:run
run: $(TARGET)
	./$(TARGET)

$(TARGET): $(BUILD_DIR)/main.o $(BUILD_DIR)/CCommandPrint.o $(BUILD_DIR)/CCommandPut.o \
		$(BUILD_DIR)/CCommandSubtract.o $(BUILD_DIR)/CCommandTranspose.o $(BUILD_DIR)/CMatrix.o \
		$(BUILD_DIR)/CMatrixSparse.o $(BUILD_DIR)/CMatrixStandard.o $(BUILD_DIR)/CMatrixStandard.o  \
		$(BUILD_DIR)/CApplicationConsole.o $(BUILD_DIR)/CApplication.o $(BUILD_DIR)/CCommandAdd.o \
		$(BUILD_DIR)/CCommand.o $(BUILD_DIR)/CCommandCut.o $(BUILD_DIR)/CCommandLoad.o $(BUILD_DIR)/CCommandMergeNextTo.o \
		$(BUILD_DIR)/CCommandMergeUnder.o $(BUILD_DIR)/CCommandMultiply.o
		$(CXX) $(CXX_FLAGS) $^ -o $@


$(BUILD_DIR)/%.o: src/%.cpp
		$(MKDIR) $(BUILD_DIR)
		$(CXX) $(CXX_FLAGS) $< -c -o $@

.PHONY: clean
clean:
	rm -rf $(TARGET) $(BUILD_DIR)/ 2>/dev/null



# Dependencies
	$(BUILD_DIR)/CApplicationConsole.o: src/CApplicationConsole.cpp \
			   src/CApplicationConsole.h src/CApplication.h src/CMatrix.h \
			   src/CMatrixStandard.h src/CMatrixSparse.h src/CCommand.h \
			   src/CCommandLoad.h src/CCommandPrint.h src/CCommandAdd.h \
			   src/CCommandSubtract.h src/CCommandMultiply.h src/CCommandPut.h \
			   src/CCommandTranspose.h src/CCommandCut.h src/CCommandMergeUnder.h \
			   src/CCommandMergeNextTo.h
	$(BUILD_DIR)/CApplication.o: src/CApplication.cpp src/CApplication.h src/CMatrix.h \
			   src/CMatrixStandard.h src/CMatrixSparse.h src/CCommand.h
	$(BUILD_DIR)/CCommandAdd.o: src/CCommandAdd.cpp src/CCommandAdd.h src/CCommand.h \
			   src/CMatrix.h
	$(BUILD_DIR)/CCommand.o: src/CCommand.cpp src/CCommand.h src/CMatrix.h
	$(BUILD_DIR)/CCommandCut.o: src/CCommandCut.cpp src/CCommandCut.h src/CCommand.h \
			   src/CMatrix.h
	$(BUILD_DIR)/CCommandLoad.o: src/CCommandLoad.cpp src/CCommandLoad.h src/CCommand.h \
			   src/CMatrix.h src/CMatrixStandard.h src/CMatrixSparse.h
	$(BUILD_DIR)/CCommandMergeNextTo.o: src/CCommandMergeNextTo.cpp \
			   src/CCommandMergeNextTo.h src/CCommand.h src/CMatrix.h
	$(BUILD_DIR)/CCommandMergeNextTo.o: src/CCommandMergeNextTo.cpp \
			   src/CCommandMergeNextTo.h src/CCommand.h src/CMatrix.h
	$(BUILD_DIR)/CCommandMergeUnder.o: src/CCommandMergeUnder.cpp src/CCommandMergeUnder.h \
			   src/CCommand.h src/CMatrix.h
	$(BUILD_DIR)/CCommandMultiply.o: src/CCommandMultiply.cpp src/CCommandMultiply.h \
			   src/CCommand.h src/CMatrix.h
	$(BUILD_DIR)/CCommandPrint.o: src/CCommandPrint.cpp src/CCommandPrint.h src/CCommand.h \
			   src/CMatrix.h
	$(BUILD_DIR)/CCommandPut.o: src/CCommandPut.cpp src/CCommandPut.h src/CCommand.h \
			   src/CMatrix.h src/CMatrixStandard.h src/CMatrixSparse.h
	$(BUILD_DIR)/CCommandSubtract.o: src/CCommandSubtract.cpp src/CCommandSubtract.h \
			   src/CMatrix.h src/CCommand.h
	$(BUILD_DIR)/CCommandTranspose.o: src/CCommandTranspose.cpp src/CCommandTranspose.h \
                 src/CCommand.h src/CMatrix.h
	$(BUILD_DIR)/CMatrix.o: src/CMatrix.cpp src/CMatrix.h
	$(BUILD_DIR)/CMatrixSparse.o: src/CMatrixSparse.cpp src/CMatrixSparse.h src/CMatrix.h \
                 src/CMatrixStandard.h
	$(BUILD_DIR)/CMatrixStandard.o: src/CMatrixStandard.cpp src/CMatrixStandard.h \
                 src/CMatrix.h src/CMatrixSparse.h
	$(BUILD_DIR)/main.o: src/main.cpp src/CMatrixStandard.h src/CMatrix.h \
                 src/CMatrixSparse.h src/CApplicationConsole.h src/CApplication.h \
                 src/CCommand.h src/CCommandLoad.h src/CCommandPrint.h src/CCommandAdd.h \
                 src/CCommandSubtract.h src/CCommandMultiply.h src/CCommandPut.h \
                 src/CCommandTranspose.h src/CCommandCut.h src/CCommandMergeUnder.h \
                 src/CCommandMergeNextTo.h



