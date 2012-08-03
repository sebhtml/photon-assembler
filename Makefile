CXX=mpicxx
CXXFLAGS=-Wall -std=c++98 -I RayPlatform -I . 
APP=photon

all: $(APP)

photon: RayPlatform/libRayPlatform.a
	$(CXX) $(CXXFLAGS) plugins/TwinProcessor/Kmer.cpp plugins/TwinProcessor/Reader.cpp photon.cpp plugins/TwinProcessor/common_functions.cpp  plugins/TwinProcessor/TwinProcessor.cpp -o $(APP)  RayPlatform/libRayPlatform.a 



RayPlatform/libRayPlatform.a:
	@cd RayPlatform; make MPICXX="$(MPICXX)" CXXFLAGS="$(CXXFLAGS)" -j $(J) ; cd ..

clean: 
	rm $(APP)


