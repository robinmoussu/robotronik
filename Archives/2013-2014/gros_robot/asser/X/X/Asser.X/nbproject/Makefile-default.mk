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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../sources/asser.c ../sources/callage.c ../sources/debug.c ../sources/fct_asser.c ../sources/init.c ../sources/main.c ../sources/message.c ../sources/motors.c ../sources/uart.c ../sources/bloquer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/592584297/asser.o ${OBJECTDIR}/_ext/592584297/callage.o ${OBJECTDIR}/_ext/592584297/debug.o ${OBJECTDIR}/_ext/592584297/fct_asser.o ${OBJECTDIR}/_ext/592584297/init.o ${OBJECTDIR}/_ext/592584297/main.o ${OBJECTDIR}/_ext/592584297/message.o ${OBJECTDIR}/_ext/592584297/motors.o ${OBJECTDIR}/_ext/592584297/uart.o ${OBJECTDIR}/_ext/592584297/bloquer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/592584297/asser.o.d ${OBJECTDIR}/_ext/592584297/callage.o.d ${OBJECTDIR}/_ext/592584297/debug.o.d ${OBJECTDIR}/_ext/592584297/fct_asser.o.d ${OBJECTDIR}/_ext/592584297/init.o.d ${OBJECTDIR}/_ext/592584297/main.o.d ${OBJECTDIR}/_ext/592584297/message.o.d ${OBJECTDIR}/_ext/592584297/motors.o.d ${OBJECTDIR}/_ext/592584297/uart.o.d ${OBJECTDIR}/_ext/592584297/bloquer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/592584297/asser.o ${OBJECTDIR}/_ext/592584297/callage.o ${OBJECTDIR}/_ext/592584297/debug.o ${OBJECTDIR}/_ext/592584297/fct_asser.o ${OBJECTDIR}/_ext/592584297/init.o ${OBJECTDIR}/_ext/592584297/main.o ${OBJECTDIR}/_ext/592584297/message.o ${OBJECTDIR}/_ext/592584297/motors.o ${OBJECTDIR}/_ext/592584297/uart.o ${OBJECTDIR}/_ext/592584297/bloquer.o

# Source Files
SOURCEFILES=../sources/asser.c ../sources/callage.c ../sources/debug.c ../sources/fct_asser.c ../sources/init.c ../sources/main.c ../sources/message.c ../sources/motors.c ../sources/uart.c ../sources/bloquer.c


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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC802
MP_LINKER_FILE_OPTION=,--script=p33FJ128MC802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/592584297/asser.o: ../sources/asser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/asser.c  -o ${OBJECTDIR}/_ext/592584297/asser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/asser.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/asser.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/callage.o: ../sources/callage.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/callage.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/callage.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/callage.c  -o ${OBJECTDIR}/_ext/592584297/callage.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/callage.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/callage.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/debug.o: ../sources/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/debug.c  -o ${OBJECTDIR}/_ext/592584297/debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/debug.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/debug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/fct_asser.o: ../sources/fct_asser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/fct_asser.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/fct_asser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/fct_asser.c  -o ${OBJECTDIR}/_ext/592584297/fct_asser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/fct_asser.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/fct_asser.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/init.o: ../sources/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/init.c  -o ${OBJECTDIR}/_ext/592584297/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/main.o: ../sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/main.c  -o ${OBJECTDIR}/_ext/592584297/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/message.o: ../sources/message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/message.c  -o ${OBJECTDIR}/_ext/592584297/message.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/message.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/message.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/motors.o: ../sources/motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/motors.c  -o ${OBJECTDIR}/_ext/592584297/motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/motors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/uart.o: ../sources/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/uart.c  -o ${OBJECTDIR}/_ext/592584297/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/bloquer.o: ../sources/bloquer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/bloquer.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/bloquer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/bloquer.c  -o ${OBJECTDIR}/_ext/592584297/bloquer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/bloquer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/bloquer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/592584297/asser.o: ../sources/asser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/asser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/asser.c  -o ${OBJECTDIR}/_ext/592584297/asser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/asser.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/asser.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/callage.o: ../sources/callage.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/callage.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/callage.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/callage.c  -o ${OBJECTDIR}/_ext/592584297/callage.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/callage.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/callage.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/debug.o: ../sources/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/debug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/debug.c  -o ${OBJECTDIR}/_ext/592584297/debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/debug.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/debug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/fct_asser.o: ../sources/fct_asser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/fct_asser.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/fct_asser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/fct_asser.c  -o ${OBJECTDIR}/_ext/592584297/fct_asser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/fct_asser.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/fct_asser.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/init.o: ../sources/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/init.c  -o ${OBJECTDIR}/_ext/592584297/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/init.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/main.o: ../sources/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/main.c  -o ${OBJECTDIR}/_ext/592584297/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/main.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/message.o: ../sources/message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/message.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/message.c  -o ${OBJECTDIR}/_ext/592584297/message.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/message.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/message.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/motors.o: ../sources/motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/motors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/motors.c  -o ${OBJECTDIR}/_ext/592584297/motors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/motors.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/motors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/uart.o: ../sources/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/uart.c  -o ${OBJECTDIR}/_ext/592584297/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/uart.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/592584297/bloquer.o: ../sources/bloquer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/592584297 
	@${RM} ${OBJECTDIR}/_ext/592584297/bloquer.o.d 
	@${RM} ${OBJECTDIR}/_ext/592584297/bloquer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../sources/bloquer.c  -o ${OBJECTDIR}/_ext/592584297/bloquer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/592584297/bloquer.o.d"        -g -omf=elf -O0 -msmart-io=1 -Werror -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/592584297/bloquer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf  -mreserve=data@0x800:0x822   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Asser.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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
