##
# quadratic_equation
#

CXX=clang++
CXXFLAGS=-c -D _DEBUG -ggdb3 -std=c++20 -Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wchar-subscripts -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -fPIE -O0
RM=rm -rf

SRC_DIR=src
LIB_DIR=lib
BUILD_DIR=build

SRCS=$(wildcard $(SRC_DIR)/*.cpp)
LIBS=$(wildcard $(LIB_DIR)/*.cpp)
OBJS=$(addprefix $(BUILD_DIR)/,$(patsubst %.cpp,%.o,$(notdir $(LIBS)) $(notdir $(SRCS))))
TARGET=$(BUILD_DIR)/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@

exec:
	$(TARGET)

clean:
	$(RM) $(BUILD_DIR)/*

# end
