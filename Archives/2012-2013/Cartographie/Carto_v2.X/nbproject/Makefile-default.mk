#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=astar.c carto.c data.c help_main.c main.c malloc.c message.c uart.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/astar.o ${OBJECTDIR}/carto.o ${OBJECTDIR}/data.o ${OBJECTDIR}/help_main.o ${OBJECTDIR}/main.o ${OBJECTDIR}/malloc.o ${OBJECTDIR}/message.o ${OBJECTDIR}/uart.o
POSSIBLE_DEPFILES=${OBJECTDIR}/astar.o.d ${OBJECTDIR}/carto.o.d ${OBJECTDIR}/data.o.d ${OBJECTDIR}/help_main.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/malloc.o.d ${OBJECTDIR}/message.o.d ${OBJECTDIR}/uart.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/astar.o ${OBJECTDIR}/carto.o ${OBJECTDIR}/data.o ${OBJECTDIR}/help_main.o ${OBJECTDIR}/main.o ${OBJECTDIR}/malloc.o ${OBJECTDIR}/message.o ${OBJECTDIR}/uart.o

# Source Files
SOURCEFILES=astar.c carto.c data.c help_main.c main.c malloc.c message.c uart.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC802
MP_LINKER_FILE_OPTION=,-Tp33FJ128MC802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/astar.o: astar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/astar.o.d 
	@${RM} ${OBJECTDIR}/astar.o.ok ${OBJECTDIR}/astar.o.err 
	@${FIXDEPS} "${OBJECTDIR}/astar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/astar.o.d" -o ${OBJECTDIR}/astar.o astar.c    
	
${OBJECTDIR}/carto.o: carto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/carto.o.d 
	@${RM} ${OBJECTDIR}/carto.o.ok ${OBJECTDIR}/carto.o.err 
	@${FIXDEPS} "${OBJECTDIR}/carto.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/carto.o.d" -o ${OBJECTDIR}/carto.o carto.c    
	
${OBJECTDIR}/data.o: data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/data.o.d 
	@${RM} ${OBJECTDIR}/data.o.ok ${OBJECTDIR}/data.o.err 
	@${FIXDEPS} "${OBJECTDIR}/data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/data.o.d" -o ${OBJECTDIR}/data.o data.c    
	
${OBJECTDIR}/help_main.o: help_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/help_main.o.d 
	@${RM} ${OBJECTDIR}/help_main.o.ok ${OBJECTDIR}/help_main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/help_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/help_main.o.d" -o ${OBJECTDIR}/help_main.o help_main.c    
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    
	
${OBJECTDIR}/malloc.o: malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/malloc.o.d 
	@${RM} ${OBJECTDIR}/malloc.o.ok ${OBJECTDIR}/malloc.o.err 
	@${FIXDEPS} "${OBJECTDIR}/malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/malloc.o.d" -o ${OBJECTDIR}/malloc.o malloc.c    
	
${OBJECTDIR}/message.o: message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/message.o.d 
	@${RM} ${OBJECTDIR}/message.o.ok ${OBJECTDIR}/message.o.err 
	@${FIXDEPS} "${OBJECTDIR}/message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/message.o.d" -o ${OBJECTDIR}/message.o message.c    
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o.ok ${OBJECTDIR}/uart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    
	
else
${OBJECTDIR}/astar.o: astar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/astar.o.d 
	@${RM} ${OBJECTDIR}/astar.o.ok ${OBJECTDIR}/astar.o.err 
	@${FIXDEPS} "${OBJECTDIR}/astar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/astar.o.d" -o ${OBJECTDIR}/astar.o astar.c    
	
${OBJECTDIR}/carto.o: carto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/carto.o.d 
	@${RM} ${OBJECTDIR}/carto.o.ok ${OBJECTDIR}/carto.o.err 
	@${FIXDEPS} "${OBJECTDIR}/carto.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/carto.o.d" -o ${OBJECTDIR}/carto.o carto.c    
	
${OBJECTDIR}/data.o: data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/data.o.d 
	@${RM} ${OBJECTDIR}/data.o.ok ${OBJECTDIR}/data.o.err 
	@${FIXDEPS} "${OBJECTDIR}/data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/data.o.d" -o ${OBJECTDIR}/data.o data.c    
	
${OBJECTDIR}/help_main.o: help_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/help_main.o.d 
	@${RM} ${OBJECTDIR}/help_main.o.ok ${OBJECTDIR}/help_main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/help_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/help_main.o.d" -o ${OBJECTDIR}/help_main.o help_main.c    
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    
	
${OBJECTDIR}/malloc.o: malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/malloc.o.d 
	@${RM} ${OBJECTDIR}/malloc.o.ok ${OBJECTDIR}/malloc.o.err 
	@${FIXDEPS} "${OBJECTDIR}/malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/malloc.o.d" -o ${OBJECTDIR}/malloc.o malloc.c    
	
${OBJECTDIR}/message.o: message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/message.o.d 
	@${RM} ${OBJECTDIR}/message.o.ok ${OBJECTDIR}/message.o.err 
	@${FIXDEPS} "${OBJECTDIR}/message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/message.o.d" -o ${OBJECTDIR}/message.o message.c    
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o.ok ${OBJECTDIR}/uart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}/pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Carto_v2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
