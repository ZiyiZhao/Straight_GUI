CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = HumanPlayer.o ComputerPlayer.o Command.o Card.o Player.o Deck.o Game.o PlayStraight.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = straights

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies