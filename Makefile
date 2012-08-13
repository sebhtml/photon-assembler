CXX=mpicxx
CXXFLAGS=-Wall -std=c++98 -I RayPlatform -I . -O3
APP=photon

all: $(APP)

photon: RayPlatform/libRayPlatform.a
	$(CXX) $(CXXFLAGS) plugins/TwinProcessor/TwinData.cpp plugins/TwinProcessor/Kmer.cpp  plugins/TwinProcessor/Sequence.cpp  photon.cpp plugins/TwinProcessor/common_functions.cpp  plugins/TwinProcessor/Reader.cpp plugins/TwinProcessor/ReaderImplementationFastq.cpp plugins/TwinProcessor/TwinProcessor.cpp -o $(APP)  RayPlatform/libRayPlatform.a 



RayPlatform/libRayPlatform.a:
	@cd RayPlatform; make MPICXX="$(MPICXX)" CXXFLAGS="$(CXXFLAGS)" -j $(J) ; cd ..

clean: 
	rm $(APP)

test:
	./photon photon.conf

