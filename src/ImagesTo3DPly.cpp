#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// Scrupt Dir
std::string openMVG_path = "../openMVG_Build/Linux-x86_64-RELEASE/";
std::string openMVE_path = "../mve/apps/";
std::string res_path = "";
 
int main(int argc, char *argv[])
{
	if(argc != 2){
		std::cout << "Wrong arguments" << "\n";
		return 0;
	}
	
	res_path = argv[1];
	

	// Image Listing
	std::string ch = openMVG_path + "openMVG_main_SfMInit_ImageListing -d ../openMVG/src/openMVG/exif/sensor_width_database/sensor_width_camera_database.txt -i " + res_path + " -o " + res_path + "output";
	system(ch.c_str());

	// Compute Features
	ch.clear();
	ch = openMVG_path + "openMVG_main_ComputeFeatures -i " + res_path + "output/sfm_data.json -o " + res_path + "output/image -n 4";
	system(ch.c_str());
	
	// Compute Matches
	ch.clear();
	ch = openMVG_path + "openMVG_main_ComputeMatches -i " + res_path + "output/sfm_data.json -o " + res_path + "output/image";
	system(ch.c_str());

	// IncrementalSfM
	ch.clear();
	ch = openMVG_path + "openMVG_main_IncrementalSfM -i " + res_path + "output/sfm_data.json -m " + res_path + "output/image -o " + res_path + "output/IncrementalRecon";
	system(ch.c_str());

	// Convert scene to MVE format
	ch.clear();
	ch = openMVG_path + "openMVG_main_openMVG2MVE2 -i " + res_path + "output/IncrementalRecon/sfm_data.bin -o " + res_path + "output/OutRecon";
	system(ch.c_str());

	// Depth Map reconstruction
	ch.clear();
	ch = openMVE_path + "dmrecon/dmrecon -s2 " + res_path + "output/OutRecon/MVE/";
	system(ch.c_str());
	// Scene to Point Set
	ch.clear();
	ch = openMVE_path + "scene2pset/scene2pset -F2 " + res_path + "output/OutRecon/MVE/ " + res_path + "output/OutRecon/MVE/pset-L2.ply";
	system(ch.c_str());
	
	// Meshing
	ch.clear();
	ch = openMVE_path + "fssrecon/fssrecon " + res_path + "output/OutRecon/MVE/pset-L2.ply " + res_path + "output/OutRecon/surface-L2.ply";
	system(ch.c_str());

	// Meshing Cleaning
	ch.clear();
	ch = openMVE_path + "meshclean/meshclean -t10 " + res_path + "output/OutRecon/surface-L2.ply " + res_path + "output/OutRecon/surface-L2-clean.ply";
	system(ch.c_str());
}