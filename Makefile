TARGET_EXEC ?= CubicServer

CXX	?=	gcc

BUILD_DIR := build
SRC_DIRS := cubic-server

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

LIB_FOLDERS := $(shell ls -d libs/*/)

INC_DIRS := $(SRC_DIRS) $(addsuffix include,$(LIB_FOLDERS))
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

CXXFLAGS := -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wconversion
CXXFLAGS += -std=c++17
CXXFLAGS += -Wp,-U_FORTIFY_SOURCE
CXXFLAGS += -Wformat=2
CXXFLAGS += -MMD -MP
# This needs to be reactivated once we know how it f****** works :3
# CXXFLAGS += -fanalyzer
CXXFLAGS += -fno-builtin
CXXFLAGS += -pipe
CXXFLAGS += -march=native -mtune=native
CXXFLAGS += -Wcast-qual
CXXFLAGS += -Wconversion
CXXFLAGS += -Wdisabled-optimization
CXXFLAGS += -Wduplicated-branches
CXXFLAGS += -Wduplicated-cond
CXXFLAGS += -Werror=return-type
CXXFLAGS += -Werror=vla-larger-than=0
CXXFLAGS += -Winit-self
CXXFLAGS += -Winline
CXXFLAGS += -Wlogical-op
CXXFLAGS += -Wredundant-decls
CXXFLAGS += -Wshadow
CXXFLAGS += -Wsuggest-attribute=pure
CXXFLAGS += -Wsuggest-attribute=const
CXXFLAGS += -Wundef
CXXFLAGS += -Wunreachable-code
CXXFLAGS += -Wwrite-strings
CXXFLAGS += -Wno-missing-field-initializers
CXXFLAGS += -fno-exceptions

LDFLAGS	:= -Llibs/cubic-protocol -lcubic-protocol

# TODO: Set this up in a more generic way
NEEDED_LIBS := libs/cubic-protocol/libcubic-protocol.a

ifeq ($(DEBUG), 1)
        CXXFLAGS += -O0 -ggdb
else
        CXXFLAGS += -O3 -DNDEBUG
        LDFLAGS += -s
endif

ifeq ($(LTO), 1)
        CXXFLAGS += -flto
		# This will break with DEBUG=1, but who the hell builds with
		# LTOs and debug at the same time?
		# I could also make it throw an error if DEBUG and LTO are activated
		# at the same time but for now this will do
        LDFLAGS += -flto -O3
endif

ifeq ($(ASAN), 1)
        CXXFLAGS += -fsanitize=address,leak,undefined
        LDFLAGS += -lasan -lubsan -fsanitize=address,leak,undefined
endif

.PHONY: all
all:
	$(MAKE) all-libs
	$(MAKE) $(TARGET_EXEC)

$(TARGET_EXEC): $(BUILD_DIR)/$(TARGET_EXEC)
	cp $(BUILD_DIR)/$(TARGET_EXEC) $(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(NEEDED_LIBS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: all-libs
all-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ all

.PHONY: clean-libs
clean-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ clean

.PHONY: fclean-libs
fclean-libs: $(LIB_FOLDERS)
	$(MAKE) -C $^ fclean

.PHONY: clean
clean: clean-libs
	rm -rf $(BUILD_DIR)

.PHONY: fclean
fclean: fclean-libs clean
	rm -f $(TARGET_EXEC)

.PHONY: re
re: fclean
	$(MAKE) all

-include $(DEPS)
