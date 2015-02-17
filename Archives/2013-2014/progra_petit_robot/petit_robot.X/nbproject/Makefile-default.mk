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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=comAsser.c comXbee.c coordonees.c debug.c init.c main_petit_robot.c mouvement.c sharp.c strategie.c uart.c uart_xbee.c timer.c servo.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/comAsser.o ${OBJECTDIR}/comXbee.o ${OBJECTDIR}/coordonees.o ${OBJECTDIR}/debug.o ${OBJECTDIR}/init.o ${OBJECTDIR}/main_petit_robot.o ${OBJECTDIR}/mouvement.o ${OBJECTDIR}/sharp.o ${OBJECTDIR}/strategie.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/uart_xbee.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/servo.o
POSSIBLE_DEPFILES=${OBJECTDIR}/comAsser.o.d ${OBJECTDIR}/comXbee.o.d ${OBJECTDIR}/coordonees.o.d ${OBJECTDIR}/debug.o.d ${OBJECTDIR}/init.o.d ${OBJECTDIR}/main_petit_robot.o.d ${OBJECTDIR}/mouvement.o.d ${OBJECTDIR}/sharp.o.d ${OBJECTDIR}/strategie.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/uart_xbee.o.d ${OBJECTDIR}/timer.o.d ${OBJECTDIR}/servo.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/comAsser.o ${OBJECTDIR}/comXbee.o ${OBJECTDIR}/coordonees.o ${OBJECTDIR}/debug.o ${OBJECTDIR}/init.o ${OBJECTDIR}/main_petit_robot.o ${OBJECTDIR}/mouvement.o ${OBJECTDIR}/sharp.o ${OBJECTDIR}/strategie.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/uart_xbee.o ${OBJECTDIR}/timer.o ${OBJECTDIR}/servo.o

# Source Files
SOURCEFILES=comAsser.c comXbee.c coordonees.c debug.c init.c main_petit_robot.c mouvement.c sharp.c strategie.c uart.c uart_xbee.c timer.c servo.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC802
MP_LINKER_FILE_OPTION=,--script=p33FJ128MC802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/comAsser.o: comAsser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/comAsser.o.d 
	@${RM} ${OBJECTDIR}/comAsser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  comAsser.c  -o ${OBJECTDIR}/comAsser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/comAsser.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/comAsser.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/comXbee.o: comXbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/comXbee.o.d 
	@${RM} ${OBJECTDIR}/comXbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  comXbee.c  -o ${OBJECTDIR}/comXbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/comXbee.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/comXbee.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/coordonees.o: coordonees.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/coordonees.o.d 
	@${RM} ${OBJECTDIR}/coordonees.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  coordonees.c  -o ${OBJECTDIR}/coordonees.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/coordonees.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/coordonees.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/debug.o: debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/debug.o.d 
	@${RM} ${OBJECTDIR}/debug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  debug.c  -o ${OBJECTDIR}/debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/debug.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/debug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/init.o: init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main_petit_robot.o: main_petit_robot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main_petit_robot.o.d 
	@${RM} ${OBJECTDIR}/main_petit_robot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main_petit_robot.c  -o ${OBJECTDIR}/main_petit_robot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main_petit_robot.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main_petit_robot.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mouvement.o: mouvement.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/mouvement.o.d 
	@${RM} ${OBJECTDIR}/mouvement.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mouvement.c  -o ${OBJECTDIR}/mouvement.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mouvement.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/mouvement.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sharp.o: sharp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/sharp.o.d 
	@${RM} ${OBJECTDIR}/sharp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sharp.c  -o ${OBJECTDIR}/sharp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sharp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/sharp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/strategie.o: strategie.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/strategie.o.d 
	@${RM} ${OBJECTDIR}/strategie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  strategie.c  -o ${OBJECTDIR}/strategie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/strategie.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/strategie.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/uart_xbee.o: uart_xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart_xbee.o.d 
	@${RM} ${OBJECTDIR}/uart_xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_xbee.c  -o ${OBJECTDIR}/uart_xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart_xbee.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/uart_xbee.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer.o: timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/servo.o: servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  servo.c  -o ${OBJECTDIR}/servo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/servo.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/servo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/comAsser.o: comAsser.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/comAsser.o.d 
	@${RM} ${OBJECTDIR}/comAsser.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  comAsser.c  -o ${OBJECTDIR}/comAsser.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/comAsser.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/comAsser.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/comXbee.o: comXbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/comXbee.o.d 
	@${RM} ${OBJECTDIR}/comXbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  comXbee.c  -o ${OBJECTDIR}/comXbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/comXbee.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/comXbee.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/coordonees.o: coordonees.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/coordonees.o.d 
	@${RM} ${OBJECTDIR}/coordonees.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  coordonees.c  -o ${OBJECTDIR}/coordonees.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/coordonees.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/coordonees.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/debug.o: debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/debug.o.d 
	@${RM} ${OBJECTDIR}/debug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  debug.c  -o ${OBJECTDIR}/debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/debug.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/debug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/init.o: init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/init.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main_petit_robot.o: main_petit_robot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main_petit_robot.o.d 
	@${RM} ${OBJECTDIR}/main_petit_robot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main_petit_robot.c  -o ${OBJECTDIR}/main_petit_robot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main_petit_robot.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main_petit_robot.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mouvement.o: mouvement.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/mouvement.o.d 
	@${RM} ${OBJECTDIR}/mouvement.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mouvement.c  -o ${OBJECTDIR}/mouvement.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mouvement.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/mouvement.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sharp.o: sharp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/sharp.o.d 
	@${RM} ${OBJECTDIR}/sharp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sharp.c  -o ${OBJECTDIR}/sharp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sharp.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/sharp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/strategie.o: strategie.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/strategie.o.d 
	@${RM} ${OBJECTDIR}/strategie.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  strategie.c  -o ${OBJECTDIR}/strategie.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/strategie.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/strategie.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/uart_xbee.o: uart_xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart_xbee.o.d 
	@${RM} ${OBJECTDIR}/uart_xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart_xbee.c  -o ${OBJECTDIR}/uart_xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart_xbee.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/uart_xbee.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer.o: timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/timer.o.d 
	@${RM} ${OBJECTDIR}/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer.c  -o ${OBJECTDIR}/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/servo.o: servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  servo.c  -o ${OBJECTDIR}/servo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/servo.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/servo.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf  -mreserve=data@0x800:0x822   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/petit_robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
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
