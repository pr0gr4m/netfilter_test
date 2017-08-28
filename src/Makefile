# Makefile - General Makefile for build
#

# include gerneral Makefile configuration file
include Makefile.inc

# object file list
OBJECTS = nfqnl_test.o common.o parsing.o

# execute file list
EXE = netfilter_test

all : ${EXE}

clean : 
	${RM} *.o ${EXE}

showall :
	@ echo ${EXE}

${EXE} : ${OBJECTS}
	${CC} ${CFLAGS} -o $@ $^ ${LINUX_LIBNETFLTR}
