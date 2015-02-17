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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../informatique/main_reception.c ../../informatique/ordonnanceur.c ../../informatique/reception.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/179175756/main_reception.o ${OBJECTDIR}/_ext/179175756/ordonnanceur.o ${OBJECTDIR}/_ext/179175756/reception.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/179175756/main_reception.o.d ${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d ${OBJECTDIR}/_ext/179175756/reception.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/179175756/main_reception.o ${OBJECTDIR}/_ext/179175756/ordonnanceur.o ${OBJECTDIR}/_ext/179175756/reception.o

# Source Files
SOURCEFILES=../../informatique/main_reception.c ../../informatique/ordonnanceur.c ../../informatique/reception.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128MC802
MP_LINKER_FILE_OPTION=,--script=p33FJ128MC802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/179175756/main_reception.o: ../../informatique/main_reception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/179175756 
	@${RM} ${OBJECTDIR}/_ext/179175756/main_reception.o.d 
	@${RM} ${OBJECTDIR}/_ext/179175756/main_reception.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../informatique/main_reception.c  -o ${OBJECTDIR}/_ext/179175756/main_reception.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/179175756/main_reception.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/179175756/main_reception.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/179175756/ordonnanceur.o: ../../informatique/ordonnanceur.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/179175756 
	@${RM} ${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d 
	@${RM} ${OBJECTDIR}/_ext/179175756/ordonnanceur.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../informatique/ordonnanceur.c  -o ${OBJECTDIR}/_ext/179175756/ordonnanceur.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/179175756/reception.o: ../../informatique/reception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/179175756 
	@${RM} ${OBJECTDIR}/_ext/179175756/reception.o.d 
	@${RM} ${OBJECTDIR}/_ext/179175756/reception.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../informatique/reception.c  -o ${OBJECTDIR}/_ext/179175756/reception.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/179175756/reception.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1    -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/179175756/reception.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/179175756/main_reception.o: ../../informatique/main_reception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/179175756 
	@${RM} ${OBJECTDIR}/_ext/179175756/main_reception.o.d 
	@${RM} ${OBJECTDIR}/_ext/179175756/main_reception.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../informatique/main_reception.c  -o ${OBJECTDIR}/_ext/179175756/main_reception.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/179175756/main_reception.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/179175756/main_reception.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/179175756/ordonnanceur.o: ../../informatique/ordonnanceur.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/179175756 
	@${RM} ${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d 
	@${RM} ${OBJECTDIR}/_ext/179175756/ordonnanceur.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../informatique/ordonnanceur.c  -o ${OBJECTDIR}/_ext/179175756/ordonnanceur.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/179175756/ordonnanceur.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/179175756/reception.o: ../../informatique/reception.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/179175756 
	@${RM} ${OBJECTDIR}/_ext/179175756/reception.o.d 
	@${RM} ${OBJECTDIR}/_ext/179175756/reception.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../informatique/reception.c  -o ${OBJECTDIR}/_ext/179175756/reception.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/179175756/reception.o.d"        -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/179175756/reception.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf  -mreserve=data@0x800:0x822   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/reception.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
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
