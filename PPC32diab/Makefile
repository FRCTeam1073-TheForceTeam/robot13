# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC32diab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/WindRiver/workspace/robot13
WS_ROOT_DIR := C:/WindRiver/workspace



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = robot13/$(MODE_DIR)/robot13.out \
	 robot13_partialImage/$(MODE_DIR)/robot13_partialImage.o


#Rules

# robot13
ifeq ($(DEBUG_MODE),1)
robot13/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
robot13/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
robot13/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
robot13/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
robot13/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
robot13/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
robot13/$(MODE_DIR)/% : IDE_LIBRARIES = 
robot13/$(MODE_DIR)/% : PROJECT_TYPE = DKM
robot13/$(MODE_DIR)/% : DEFINES = 
robot13/$(MODE_DIR)/% : EXPAND_DBG = 0
robot13/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
robot13/$(MODE_DIR)/% : CPU = PPC32
robot13/$(MODE_DIR)/% : TOOL_FAMILY = diab
robot13/$(MODE_DIR)/% : TOOL = diab
robot13/$(MODE_DIR)/% : TOOL_PATH = 
robot13/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
robot13/$(MODE_DIR)/% : LIBPATH = 
robot13/$(MODE_DIR)/% : LIBS = 
robot13/$(MODE_DIR)/% : OBJ_DIR := robot13/$(MODE_DIR)

OBJECTS_robot13 = robot13_partialImage/$(MODE_DIR)/robot13_partialImage.o

robot13/$(MODE_DIR)/robot13.out : $(OBJECTS_robot13)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_robot13) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_robot13) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

robot13/$(MODE_DIR)/robot13_compile_file : $(FILE) ;

_clean :: robot13/$(MODE_DIR)/robot13_clean

robot13/$(MODE_DIR)/robot13_clean : 
	$(TRACE_FLAG)if [ -d "robot13" ]; then cd "robot13"; rm -rf $(MODE_DIR); fi


# robot13_partialImage
ifeq ($(DEBUG_MODE),1)
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
robot13_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
robot13_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
robot13_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = -L C:/WindRiver/WPILib 
robot13_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
robot13_partialImage/$(MODE_DIR)/% : DEFINES = 
robot13_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
robot13_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
robot13_partialImage/$(MODE_DIR)/% : CPU = PPC32
robot13_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
robot13_partialImage/$(MODE_DIR)/% : TOOL = diab
robot13_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
robot13_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
robot13_partialImage/$(MODE_DIR)/% : LIBPATH = 
robot13_partialImage/$(MODE_DIR)/% : LIBS = 
robot13_partialImage/$(MODE_DIR)/% : OBJ_DIR := robot13_partialImage/$(MODE_DIR)

robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/AutonomousCommand.o : C:/WindRiver/workspace/robot13/Commands/AutonomousCommand.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/CollectDiscs.o : C:/WindRiver/workspace/robot13/Commands/CollectDiscs.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/DiscsReverse.o : C:/WindRiver/workspace/robot13/Commands/DiscsReverse.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/JoystickDrive.o : C:/WindRiver/workspace/robot13/Commands/JoystickDrive.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/LightOn.o : C:/WindRiver/workspace/robot13/Commands/LightOn.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/Shoot.o : C:/WindRiver/workspace/robot13/Commands/Shoot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/ShooterOff.o : C:/WindRiver/workspace/robot13/Commands/ShooterOff.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/ShooterOn.o : C:/WindRiver/workspace/robot13/Commands/ShooterOn.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/TestSmartDashboard.o : C:/WindRiver/workspace/robot13/Commands/TestSmartDashboard.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/OI.o : C:/WindRiver/workspace/robot13/OI.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Robot.o : C:/WindRiver/workspace/robot13/Robot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/RobotMap.o : C:/WindRiver/workspace/robot13/RobotMap.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Climber.o : C:/WindRiver/workspace/robot13/Subsystems/Climber.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Collector.o : C:/WindRiver/workspace/robot13/Subsystems/Collector.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/DriveTrain.o : C:/WindRiver/workspace/robot13/Subsystems/DriveTrain.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Light.o : C:/WindRiver/workspace/robot13/Subsystems/Light.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Navigation.o : C:/WindRiver/workspace/robot13/Subsystems/Navigation.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Shooter.o : C:/WindRiver/workspace/robot13/Subsystems/Shooter.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_robot13_partialImage = robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/AutonomousCommand.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/CollectDiscs.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/DiscsReverse.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/JoystickDrive.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/LightOn.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/Shoot.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/ShooterOff.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/ShooterOn.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/TestSmartDashboard.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/OI.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Robot.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/RobotMap.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Climber.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Collector.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/DriveTrain.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Light.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Navigation.o \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Shooter.o

robot13_partialImage/$(MODE_DIR)/robot13_partialImage.o : $(OBJECTS_robot13_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5  -o "$@" $(OBJECTS_robot13_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

robot13_partialImage/$(MODE_DIR)/robot13_partialImage_compile_file : $(FILE) ;

_clean :: robot13_partialImage/$(MODE_DIR)/robot13_partialImage_clean

robot13_partialImage/$(MODE_DIR)/robot13_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "robot13_partialImage" ]; then cd "robot13_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/AutonomousCommand.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/CollectDiscs.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/DiscsReverse.d \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/JoystickDrive.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/LightOn.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/Shoot.d \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/ShooterOff.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/ShooterOn.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Commands/TestSmartDashboard.d \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/OI.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Robot.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/RobotMap.d \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Climber.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Collector.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/DriveTrain.d \
	 robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Light.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Navigation.d robot13_partialImage/$(MODE_DIR)/Objects/robot13/Subsystems/Shooter.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

JOBS?=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS);\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
