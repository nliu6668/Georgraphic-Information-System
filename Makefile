#BufferPool.o CommandProcess.0 CoordinateIndex.0 GISRecord.o NameIndex.o SystemManager.o

GIS:main.o logger.o GISRecord.o CommandProcessor.o BufferPool.o SystemManager.o NameIndex.o
	g++ -std=c++11 main.o logger.o GISRecord.o CommandProcessor.o BufferPool.o SystemManager.o  NameIndex.o -o GIS

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

log.o:logger.cpp logger.h
	g++ -std=c++11 -c logger.cpp

BufferPool.o:BufferPool.cpp BufferPool.h
	g++ -std=c++11 -c BufferPool.cpp

CommandProcessor.0:CommandProcessor.cpp CommandProcessor.h
	g++ -std=c++11 -c CommandProcessor.cpp

GISRecord.o:GISRecord.cpp GISRecord.h
	g++ -std=c++11 -c GISRecord.cpp

NameIndex.o:NameIndex.cpp NameIndex.h
	g++ -std=c++11 -c NameIndex.cpp

SystemManager.o:SystemManager.cpp SystemManager.h
	g++ -std=c++11 -c SystemManager.cpp

clean:
	rm -rf *.o main
