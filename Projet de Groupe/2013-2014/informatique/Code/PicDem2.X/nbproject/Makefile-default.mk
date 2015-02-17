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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Buttons.c ../I2c.c ../Lcd.c ../Rtc.c ../Serial.c ../Sound.c ../Voltmeter.c ../main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/Buttons.o ${OBJECTDIR}/_ext/1472/I2c.o ${OBJECTDIR}/_ext/1472/Lcd.o ${OBJECTDIR}/_ext/1472/Rtc.o ${OBJECTDIR}/_ext/1472/Serial.o ${OBJECTDIR}/_ext/1472/Sound.o ${OBJECTDIR}/_ext/1472/Voltmeter.o ${OBJECTDIR}/_ext/1472/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/Buttons.o.d ${OBJECTDIR}/_ext/1472/I2c.o.d ${OBJECTDIR}/_ext/1472/Lcd.o.d ${OBJECTDIR}/_ext/1472/Rtc.o.d ${OBJECTDIR}/_ext/1472/Serial.o.d ${OBJECTDIR}/_ext/1472/Sound.o.d ${OBJECTDIR}/_ext/1472/Voltmeter.o.d ${OBJECTDIR}/_ext/1472/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Buttons.o ${OBJECTDIR}/_ext/1472/I2c.o ${OBJECTDIR}/_ext/1472/Lcd.o ${OBJECTDIR}/_ext/1472/Rtc.o ${OBJECTDIR}/_ext/1472/Serial.o ${OBJECTDIR}/_ext/1472/Sound.o ${OBJECTDIR}/_ext/1472/Voltmeter.o ${OBJECTDIR}/_ext/1472/main.o

# Source Files
SOURCEFILES=../Buttons.c ../I2c.c ../Lcd.c ../Rtc.c ../Serial.c ../Sound.c ../Voltmeter.c ../main.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K22
MP_PROCESSOR_OPTION_LD=18f46k22
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Buttons.o: ../Buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Buttons.o   ../Buttons.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Buttons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Buttons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/I2c.o: ../I2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/I2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/I2c.o   ../I2c.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/I2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/I2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Lcd.o: ../Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Lcd.o   ../Lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Rtc.o: ../Rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Rtc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Rtc.o   ../Rtc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Rtc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Rtc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Serial.o: ../Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Serial.o   ../Serial.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Sound.o: ../Sound.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Sound.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Sound.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Sound.o   ../Sound.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Sound.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Sound.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Voltmeter.o: ../Voltmeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Voltmeter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Voltmeter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Voltmeter.o   ../Voltmeter.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Voltmeter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Voltmeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1472/Buttons.o: ../Buttons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Buttons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Buttons.o   ../Buttons.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Buttons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Buttons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/I2c.o: ../I2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/I2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/I2c.o   ../I2c.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/I2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/I2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Lcd.o: ../Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Lcd.o   ../Lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Rtc.o: ../Rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Rtc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Rtc.o   ../Rtc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Rtc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Rtc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Serial.o: ../Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Serial.o   ../Serial.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Sound.o: ../Sound.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Sound.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Sound.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Sound.o   ../Sound.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Sound.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Sound.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/Voltmeter.o: ../Voltmeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Voltmeter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Voltmeter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/Voltmeter.o   ../Voltmeter.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/Voltmeter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Voltmeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -oi -I".." -I"../../../../../../../../../../MCC18/h" -ms -oa- -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -l"../../../../../../../../../../MCC18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -l"../../../../../../../../../../MCC18/lib"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/PicDem2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
