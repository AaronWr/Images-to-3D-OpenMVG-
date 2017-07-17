#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Scrupt Dir
char openMVG_path[] = "../openMVG_Build/Linux-x86_64-RELEASE/";
char openMVE_path[] = "../mve/apps/";

int main (int ac, char** av) {
	
	// Image Listing
	char ch[255] = "";
	strcat(ch, openMVG_path);
	strcat(ch, "openMVG_main_SfMInit_ImageListing");
	strcat(ch, " -d ../openMVG/src/openMVG/exif/sensor_width_database/sensor_width_camera_database.txt");
	strcat(ch, " -i ../res/images");
	strcat(ch, " -o ../res/output");
	system(ch);
	
	// Compute Features
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVG_path);
	strcat(ch, "openMVG_main_ComputeFeatures");
	strcat(ch, " -i ../res/output/sfm_data.json");
	strcat(ch, " -o ../res/output/image");
	strcat(ch, " -n 4");
	system(ch);
	
	// Compute Matches
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVG_path);
	strcat(ch, "openMVG_main_ComputeMatches");
	strcat(ch, " -i ../res/output/sfm_data.json");
	strcat(ch, " -o ../res/output/image");
	system(ch);

	// IncrementalSfM
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVG_path);
	strcat(ch, "openMVG_main_IncrementalSfM");
	strcat(ch, " -i ../res/output/sfm_data.json");
	strcat(ch, " -m ../res/output/image");
	strcat(ch, " -o ../res/output/IncrementalRecon");
	system(ch);

	// Convert scene to MVE format
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVG_path);
	strcat(ch, "openMVG_main_openMVG2MVE2");
	strcat(ch, " -i ../res/output/IncrementalRecon/sfm_data.bin");
	strcat(ch, " -o ../res/output/OutRecon");
	system(ch);
	
	// Depth Map reconstruction
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVE_path);
	strcat(ch, "dmrecon/dmrecon");
	strcat(ch, " -s2 ../res/output/OutRecon/MVE/");
	system(ch);
	
	// Scene to Point Set
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVE_path);
	strcat(ch, "scene2pset/scene2pset");
	strcat(ch, " -F2 ../res/output/OutRecon/MVE/ ../res/output/OutRecon/MVE/pset-L2.ply");
	system(ch);

	// Meshing
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVE_path);
	strcat(ch, "fssrecon/fssrecon");
	strcat(ch, " ../res/output/OutRecon/MVE/pset-L2.ply ../res/output/OutRecon/surface-L2.ply");
	system(ch);

	// Meshing Cleaning
	memset(ch, 0, sizeof ch);
	strcat(ch, openMVE_path);
	strcat(ch, "meshclean/meshclean");
	strcat(ch, " -t10 ../res/output/OutRecon/surface-L2.ply ../res/output/OutRecon/surface-L2-clean.ply");
	system(ch);
}