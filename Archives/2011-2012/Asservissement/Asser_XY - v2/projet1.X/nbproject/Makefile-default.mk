#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/592584297/main.o ${OBJECTDIR}/_ext/592584297/motors.o ${OBJECTDIR}/_ext/592584297/message.o ${OBJECTDIR}/_ext/592584297/init.o ${OBJECTDIR}/_ext/592584297/asser.o ${OBJECTDIR}/_ext/592584297/debug.o ${OBJECTDIR}/_ext/592584297/uart.o ${OBJECTDIR}/_ext/592584297/myMath.o ${OBJECTDIR}/_ext/592584297/exception.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/592584297/main.o.d ${OBJECTDIR}/_ext/592584297/motors.o.d ${OBJECTDIR}/_ext/592584297/message.o.d ${OBJECTDIR}/_ext/592584297/init.o.d ${OBJECTDIR}/_ext/592584297/asser.o.d ${OBJECTDIR}/_ext/592584297/debug.o.d ${OBJECTDIR}/_ext/592584297/uart.o.d ${OBJECTDIR}/_ext/592584297/myMath.o.d ${OBJECTDIR}/_ext/592584297/exception.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/592584297/main.o ${OBJECTDIR}/_ext/592584297/motors.o ${OBJECTDIR}/_ext/592584297/message.o ${OBJECTDIR}/_ext/592584297/init.o ${OBJECTDIR}/_ext/592584297/asser.o ${OBJECTDIR}/_ext/592584297/debug.o ${OBJECTDIR}/_ext/592584297/uart.o ${OBJECTDIR}/_ext/592584297/myMath.o ${OBJECTDIR}/_ext/592584297/exception.o


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/592584297/main.o: ../sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o.ok ${OBJECTDIR}/_ext/592584297/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/main.o.d" -o ${OBJECTDIR}/_ext/592584297/main.o ../sources/main.c    
	
${OBJECTDIR}/_ext/592584297/motors.o: ../sources/motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o.ok ${OBJECTDIR}/_ext/592584297/motors.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/motors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/motors.o.d" -o ${OBJECTDIR}/_ext/592584297/motors.o ../sources/motors.c    
	
${OBJECTDIR}/_ext/592584297/message.o: ../sources/message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o.ok ${OBJECTDIR}/_ext/592584297/message.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/message.o.d" -o ${OBJECTDIR}/_ext/592584297/message.o ../sources/message.c    
	
${OBJECTDIR}/_ext/592584297/init.o: ../sources/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o.ok ${OBJECTDIR}/_ext/592584297/init.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/init.o.d" -o ${OBJECTDIR}/_ext/592584297/init.o ../sources/init.c    
	
${OBJECTDIR}/_ext/592584297/asser.o: ../sources/asser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o.ok ${OBJECTDIR}/_ext/592584297/asser.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/asser.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/asser.o.d" -o ${OBJECTDIR}/_ext/592584297/asser.o ../sources/asser.c    
	
${OBJECTDIR}/_ext/592584297/debug.o: ../sources/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o.ok ${OBJECTDIR}/_ext/592584297/debug.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/debug.o.d" -o ${OBJECTDIR}/_ext/592584297/debug.o ../sources/debug.c    
	
${OBJECTDIR}/_ext/592584297/uart.o: ../sources/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o.ok ${OBJECTDIR}/_ext/592584297/uart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/uart.o.d" -o ${OBJECTDIR}/_ext/592584297/uart.o ../sources/uart.c    
	
${OBJECTDIR}/_ext/592584297/myMath.o: ../sources/myMath.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/myMath.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/myMath.o.ok ${OBJECTDIR}/_ext/592584297/myMath.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/myMath.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/myMath.o.d" -o ${OBJECTDIR}/_ext/592584297/myMath.o ../sources/myMath.c    
	
${OBJECTDIR}/_ext/592584297/exception.o: ../sources/exception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/exception.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/exception.o.ok ${OBJECTDIR}/_ext/592584297/exception.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/exception.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/exception.o.d" -o ${OBJECTDIR}/_ext/592584297/exception.o ../sources/exception.c    
	
else
${OBJECTDIR}/_ext/592584297/main.o: ../sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o.ok ${OBJECTDIR}/_ext/592584297/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/main.o.d" -o ${OBJECTDIR}/_ext/592584297/main.o ../sources/main.c    
	
${OBJECTDIR}/_ext/592584297/motors.o: ../sources/motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o.ok ${OBJECTDIR}/_ext/592584297/motors.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/motors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/motors.o.d" -o ${OBJECTDIR}/_ext/592584297/motors.o ../sources/motors.c    
	
${OBJECTDIR}/_ext/592584297/message.o: ../sources/message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o.ok ${OBJECTDIR}/_ext/592584297/message.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/message.o.d" -o ${OBJECTDIR}/_ext/592584297/message.o ../sources/message.c    
	
${OBJECTDIR}/_ext/592584297/init.o: ../sources/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o.ok ${OBJECTDIR}/_ext/592584297/init.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/init.o.d" -o ${OBJECTDIR}/_ext/592584297/init.o ../sources/init.c    
	
${OBJECTDIR}/_ext/592584297/asser.o: ../sources/asser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o.ok ${OBJECTDIR}/_ext/592584297/asser.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/asser.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/asser.o.d" -o ${OBJECTDIR}/_ext/592584297/asser.o ../sources/asser.c    
	
${OBJECTDIR}/_ext/592584297/debug.o: ../sources/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o.ok ${OBJECTDIR}/_ext/592584297/debug.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/debug.o.d" -o ${OBJECTDIR}/_ext/592584297/debug.o ../sources/debug.c    
	
${OBJECTDIR}/_ext/592584297/uart.o: ../sources/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o.ok ${OBJECTDIR}/_ext/592584297/uart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/uart.o.d" -o ${OBJECTDIR}/_ext/592584297/uart.o ../sources/uart.c    
	
${OBJECTDIR}/_ext/592584297/myMath.o: ../sources/myMath.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/myMath.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/myMath.o.ok ${OBJECTDIR}/_ext/592584297/myMath.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/myMath.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/myMath.o.d" -o ${OBJECTDIR}/_ext/592584297/myMath.o ../sources/myMath.c    
	
${OBJECTDIR}/_ext/592584297/exception.o: ../sources/exception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/exception.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/exception.o.ok ${OBJECTDIR}/_ext/592584297/exception.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/exception.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I"../sources" -MMD -MF "${OBJECTDIR}/_ext/592584297/exception.o.d" -o ${OBJECTDIR}/_ext/592584297/exception.o ../sources/exception.c    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-L"..",-Map="${DISTDIR}/projet1.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-L"..",-Map="${DISTDIR}/projet1.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/projet1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
