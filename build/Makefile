CPP = g++
CPPFLAGS = -O2 -Wall -Wno-missing-braces -I ../include/
LDLIBS = -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

../test.exe: ../graphics.cpp update.o check.o insert.o initialization.o movement.o card.o stack.o grid.o
	$(CPP) ../graphics.cpp update.o check.o insert.o initialization.o movement.o card.o stack.o grid.o -o ../test.exe $(CPPFLAGS) $(LDLIBS)


#Logic files
update.o: ../update.cpp ../include/logic.h
	$(CPP) ../update.cpp -c $(CPPFLAGS)

check.o: ../check.cpp ../include/logic.h
	$(CPP) ../check.cpp -c $(CPPFLAGS)

insert.o: ../insert.cpp ../include/logic.h
	$(CPP) ../insert.cpp -c $(CPPFLAGS)

initialization.o: ../initialization.cpp ../include/logic.h
	$(CPP) ../initialization.cpp -c $(CPPFLAGS)

movement.o: ../movement.cpp ../include/logic.h
	$(CPP) ../movement.cpp -c $(CPPFLAGS)


#Visuals files
card.o: ../card.cpp ../include/graphics.h
	$(CPP) ../card.cpp -c $(CPPFLAGS) $(LDLIBS)

stack.o: ../stack.cpp ../include/graphics.h
	$(CPP) ../stack.cpp -c $(CPPFLAGS) $(LDLIBS)

grid.o: ../grid.cpp ../include/graphics.h
	$(CPP) ../grid.cpp ../card.cpp ../stack.cpp -c $(CPPFLAGS) $(LDLIBS)
