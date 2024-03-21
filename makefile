##################################
#
# MACROS
##################################



# $(1) : compilador 
# $(2) : objetos
# $(3) : fuentes 
# $(4) : includes
# $(5) : flags
# ############################### 
define COMPILE

$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

define C2O
$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1)))
endef



define C2H
$(patsubst %.cpp,%.hpp,$(1))
endef

##################################
#CONFIG
#################################
APP        := game
GPP         := g++
SRC        := src
OBJ        := obj
CCFLAGS    := -Wall -pedantic -std=c++17 
LIB        := -lsfml-window -lsfml-graphics -lsfml-system
LIBDIR     := libs
INCLUDEDIR := -I$(SRC) -I$(LIBDIR)
MKDIR      := mkdir -p


ALLCPPS   := $(shell find $(SRC) -type f -iname *.cpp)
ALLOBJ    := $(foreach F,$(ALLCPPS),$(call C2O,$(F)))
SUBDIR    := $(shell find $(SRC) -type d)
OBJSUBDIR := $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIR))

.PHONY: info


$(APP) : $(OBJSUBDIR) $(ALLOBJ)
	$(GPP) -o $(APP) $(ALLOBJ) $(LIB) $(CCFLAGS)

$(foreach F,$(ALLCPPS),$(eval $(call COMPILE,$(GPP),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS) $(INCLUDEDIR))))

  




info:
	$(info $(ALLCPPS))
	$(info $(SUBDIR))
	$(info $(ALLOBJ))
	$(info $(OBJSUBDIR))


$(OBJSUBDIR) :
	$(MKDIR) $(OBJSUBDIR)

clean:
	$(RM) -r "./$(OBJ)"

cleanall: clean
	$(RM) "./$(APP)"





