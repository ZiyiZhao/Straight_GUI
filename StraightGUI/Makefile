CXX= g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags`
LDFLAGS=`pkg-config gtkmm-2.4 --libs`
OBJS = HumanPlayer.o ComputerPlayer.o Command.o Card.o Player.o Deck.o GameTable.o FacadeAdapter.o DialogView.o subject.o model.o controller.o DeckGUI.o PlayerHandView.o TableView.o PlayerStatusView.o view.o main.o 
EXEC = mvc

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(EXEC)

clean:
	rm $(EXEC) $(OBJS)

DeckGUI.o: DeckGUI.h DeckGUI.cc
model.o: subject.h model.h model.cc
subject.o: subject.h subject.cc
controller.o: controller.h model.h controller.cc
view.o: view.h observer.h controller.h model.h subject.h DeckGUI.h view.cc
main.o: view.h controller.h model.h main.cc
PlayerStatusView.o: PlayerStatusView.h controller.h model.h PlayerStatusView.cc
TableView.o: TableView.h controller.h model.h DeckGUI.h TableView.cc
PlayerHandView.o: PlayerHandView.h model.h DeckGUI.h PlayerHandView.cc
DialogView.o: DialogView.h DialogView.cc
FacadeAdapter.o: FacadeAdapter.h GameTable.h HumanPlayer.h ComputerPlayer.h FacadeAdapter.cc
GameTable.o: GameTable.h Deck.h GameTable.cc