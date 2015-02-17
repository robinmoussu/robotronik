#
# Generated Makefile - do not edit!
#
#
# This file contains information about the location of compilers and other tools.
# If you commmit this file into your revision control server, you will be able to 
# to checkout the project and build it from the command line with make. However,
# if more than one person works on the same project, then this file might show
# conflicts since different users are bound to have compilers in different places.
# In that case you might choose to not commit this file and let MPLAB X recreate this file
# for each user. The disadvantage of not commiting this file is that you must run MPLAB X at
# least once so the file gets created and the project can be built. Finally, you can also
# avoid using this file at all if you are only building from the command line with make.
# You can invoke make with the values of the macros:
# $ makeMP_CC="/opt/microchip/mplabc30/v3.30c/bin/pic30-gcc" ...  
#
<<<<<<< .mine
SHELL=cmd.exe
PATH_TO_IDE_BIN=C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/
=======
PATH_TO_IDE_BIN=/opt/microchip/mplabx/mplab_ide/mplab_ide/modules/../../bin/
>>>>>>> .r740
# Adding MPLAB X bin directory to path.
<<<<<<< .mine
PATH:=C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/:$(PATH)
=======
PATH:=/opt/microchip/mplabx/mplab_ide/mplab_ide/modules/../../bin/:$(PATH)
>>>>>>> .r740
# Path to java used to run MPLAB X when this makefile was created
<<<<<<< .mine
MP_JAVA_PATH="C:\Program Files (x86)\Microchip\MPLABX\sys\java\jre1.7.0_25-windows-x64\java-windows/bin/"
=======
MP_JAVA_PATH="/opt/microchip/mplabx/sys/java/jre1.7.0_25/bin/"
>>>>>>> .r740
OS_CURRENT="$(shell uname -s)"
<<<<<<< .mine
MP_CC="C:\Program Files (x86)\Microchip\xc16\v1.20\bin\xc16-gcc.exe"
=======
MP_CC="/opt/microchip/xc16/v1.21/bin/xc16-gcc"
>>>>>>> .r740
# MP_CPPC is not defined
# MP_BC is not defined
# MP_AS is not defined
# MP_LD is not defined
<<<<<<< .mine
MP_AR="C:\Program Files (x86)\Microchip\xc16\v1.20\bin\xc16-ar.exe"
DEP_GEN=${MP_JAVA_PATH}java -jar "C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/extractobjectdependencies.jar" 
MP_CC_DIR="C:\Program Files (x86)\Microchip\xc16\v1.20\bin"
=======
MP_AR="/opt/microchip/xc16/v1.21/bin/xc16-ar"
DEP_GEN=${MP_JAVA_PATH}java -jar "/opt/microchip/mplabx/mplab_ide/mplab_ide/modules/../../bin/extractobjectdependencies.jar" 
MP_CC_DIR="/opt/microchip/xc16/v1.21/bin"
>>>>>>> .r740
# MP_CPPC_DIR is not defined
# MP_BC_DIR is not defined
# MP_AS_DIR is not defined
# MP_LD_DIR is not defined
<<<<<<< .mine
MP_AR_DIR="C:\Program Files (x86)\Microchip\xc16\v1.20\bin"
=======
MP_AR_DIR="/opt/microchip/xc16/v1.21/bin"
>>>>>>> .r740
# MP_BC_DIR is not defined
