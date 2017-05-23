#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//======================================
// Hard Drive Performance Calculator
//======================================

//global variables
const int TOTAL_TRACKS = 42;


//functions
int findSectorsPerTrack(int trackNum);
int findTotalSectorsOnDisk();
int findTrackNumber(int sectorNum);
void testTrackFunctions();

float findSeekTime(int trackStart, int trackEnd);
void testSeekTime();

float findRotationsPS(int rotationsPM);
float findAvgRotDelay(int rotationsPM);
float findReadTime(int trackNum, int rotationsPM);
void testRotationTimes();

float findAccessTime(int initialTrackNum, int sectorNum, int rotationsPM);
float findAvgAccessReadTime(int rotationsPM);
float findRandAvgAccessReadTime(int rotationsPM);
void testAccessTimes();

void hardDriveStats();


//main function
int main() {
    testTrackFunctions();
    testSeekTime();
    testRotationTimes();
    testAccessTimes();
    hardDriveStats();

    return 0;
}

//calculate number of sectors for a specific track
int findSectorsPerTrack(int trackNum){
    int numSectors = 0;
    const int ADDITIONAL_SECTORS_PER_TRACK_GROUP = 2;
    const int BASE_SECTORS_PER_TRACK = 8;
    const int TRACK_GROUP_RATIO = 4;

    numSectors = (ADDITIONAL_SECTORS_PER_TRACK_GROUP*floor(trackNum/TRACK_GROUP_RATIO)) + BASE_SECTORS_PER_TRACK;
    return numSectors;
}

//calculate total number of sectors on disk
int findTotalSectorsOnDisk(){
    int sectorSum = 0;

    for(int i = 0; i < TOTAL_TRACKS; i++){
        sectorSum += findSectorsPerTrack(i);
    }

    return sectorSum;
}

//calculate a track number from a sector number
int findTrackNumber(int sectorNum){
    int trackNum = 0;
    int sectorSum = 0;

    while(sectorSum <= sectorNum){
        sectorSum += findSectorsPerTrack(trackNum);

        if(sectorSum <= sectorNum){
            trackNum++;
        }
    }

    return trackNum;
}

//tests track functions
void testTrackFunctions(){
    const int WIDTH = 11;

    //title
    cout << "TESTING: Track Functions" << endl;
    cout << "------------------------" << endl;


    //sectors in each track
    cout << "Now displaying the [track #] to [sectors per track] mapping:" << endl;
    cout << setw(WIDTH) << "Track#" << setw(WIDTH) << "#Sectors" << endl;
    for(int i = 0; i < TOTAL_TRACKS; i++){
        cout << setw(WIDTH) << i << setw(WIDTH) << findSectorsPerTrack(i) << endl;
    }
    cout << endl << "Total # Sectors: " << findTotalSectorsOnDisk() << endl << endl;


    //sector number to track number
    cout << "Now displaying the [sector number] to [track number] mapping:" << endl;
    cout << "Checking every sector at start." << endl;
    cout << setw(WIDTH) << "Sector" << setw(WIDTH) << "Track" << endl;

    const int SECTOR_NUM_CHECK = 24;
    for(int i = 0; i <= SECTOR_NUM_CHECK; i++){
        cout << setw(WIDTH) << i << setw(WIDTH) << findTrackNumber(i) << endl;
    }
    cout << endl;


    //checking every 13th sector
    cout << "Checking every 13th sector." << endl;
    cout << setw(WIDTH) << "Sector" << setw(WIDTH) << "Track" << endl;
    int trackCount = 0;
    int sectorCount = 25;
    const int INCREMENT = 13;

    while(true){
        trackCount = findTrackNumber(sectorCount);
        if(trackCount >= TOTAL_TRACKS){
            break;
        }
        cout << setw(WIDTH) << sectorCount << setw(WIDTH) << trackCount << endl;
        sectorCount += INCREMENT;
    }
    cout << endl;
}

//calculate seek time
float findSeekTime(int trackStart, int trackEnd){
    float seekTime = 0;
    const float MOVE_RATE = 0.002;
    seekTime = (abs(trackStart-trackEnd)) * MOVE_RATE;
    return seekTime;
}

//test seek time
void testSeekTime(){
    const int DECIMALS = 3;
    const int WIDTH_ONE = 6;
    const int WIDTH_TWO = 5;

    cout << "TESTING: Seek Times" << endl;
    cout << "-------------------" << endl;
    cout << "Now displaying the [track #] to [track #] seek times." << endl;
    cout << "Starting track shown down left most column; ending track in first row." << endl;
    cout << "From:";

    for(int i = 0; i < TOTAL_TRACKS; i++){
        cout << setw(WIDTH_ONE) << i;
    }
    cout << endl;

    cout << fixed << setprecision(DECIMALS);
    for(int trackStart = 0; trackStart < TOTAL_TRACKS; trackStart++){
        cout << setw(WIDTH_TWO) << trackStart << " ";
        for(int trackEnd = 0; trackEnd < TOTAL_TRACKS; trackEnd++){
            cout << findSeekTime(trackStart, trackEnd) << " ";
        }
        cout << endl << endl;
    }
}

//calculate RPS from RPM
float findRotationsPS(int rotationsPM){
    float rotationsPS = 0;
    const float SECONDS_PER_MINUTE = 60;
    rotationsPS = rotationsPM/SECONDS_PER_MINUTE;
    return rotationsPS;
}

//calculate average rotational delay time
float findAvgRotDelay(int rotationsPM){
    float rotationalDelay = 0;
    const float ROTATIONAL_DELAY = 0.5;

    rotationalDelay = (1/(findRotationsPS(rotationsPM))) * ROTATIONAL_DELAY;
    return rotationalDelay;
}

//calculate time to read one sector
float findReadTime(int trackNum, int rotationsPM){
    float readTime = 0;
    int sectorSum = 0;

    sectorSum = findSectorsPerTrack(trackNum);
    readTime = (1/findRotationsPS(rotationsPM))/sectorSum;
    return readTime;
}

//test rotation times
void testRotationTimes(){
    const int SPEED_DECIMALS = 2;
    const int TIME_DECIMALS = 6;
    const int WIDTH_ONE = 6;
    const int WIDTH_TWO = 8;
    const int WIDTH_THREE = 16;
    const int TRACK_ONE = 1;
    const int FINAL_TRACK = TOTAL_TRACKS - 1;

    cout << "TESTING: Rotation Times" << endl;
    cout << "-----------------------" << endl;
    cout << "Now displaying the [rotation delay] per [track]." << endl;
    cout << setw(WIDTH_ONE) << "RPM" << setw(WIDTH_TWO) << "RPS" << setw(WIDTH_THREE) << "Rotation Delay";
    cout << setw(WIDTH_THREE) << "Read Track 1" << setw(WIDTH_THREE) << "Read Max Track" << endl;
    cout << fixed;

    int rotationsPM = 4000;
    const int MAX_ROTATION = 16000;
    const int ROTATION_INCREMENT = 1000;
    for(rotationsPM; rotationsPM < MAX_ROTATION; rotationsPM += ROTATION_INCREMENT){
        cout << setw(WIDTH_ONE) << rotationsPM << setw(WIDTH_TWO) << setprecision(SPEED_DECIMALS);
        cout << findRotationsPS(rotationsPM) << setprecision(TIME_DECIMALS) << setw(WIDTH_THREE);
        cout << findAvgRotDelay(rotationsPM) << setw(WIDTH_THREE) << findReadTime(TRACK_ONE, rotationsPM);
        cout << setw(WIDTH_THREE) << findReadTime(FINAL_TRACK, rotationsPM)<< endl ;
    }
    cout << endl;
}

//calculate average time to access and read sector
float findAccessTime(int initialTrackNum, int sectorNum, int rotationsPM){
    float accessTime = 0;
    int finalTrackNum = 0;
    finalTrackNum = findTrackNumber(sectorNum);
    //seek time + average rotational delay + sector read time
    accessTime = findSeekTime(initialTrackNum, finalTrackNum) + findAvgRotDelay(rotationsPM) + findReadTime(finalTrackNum, rotationsPM);

    return accessTime;
}

//calculate average access and read time
float findAvgAccessReadTime(int rotationsPM){
    float sum = 0;
    int sectorSum = 0;
    int combinationCount = 0;
    sectorSum = findTotalSectorsOnDisk();

    for (int currentTrack = 0; currentTrack < TOTAL_TRACKS; currentTrack++){
        for (int currentSector = 0; currentSector < sectorSum; currentSector++){
            sum += findAccessTime(currentTrack, currentSector, rotationsPM);
            combinationCount++;
        }
    }

    return sum/combinationCount;
}

//calculate average access read time using randomized approach
float findRandAvgAccessReadTime(int rotationsPM){
    const int TRIALS = 1000000;
    float sum = 0;
    int track = 0;
    int sector = 0;

    srand(time(nullptr));

    for (int i = 0; i < TRIALS; i++){
        track = rand() % TOTAL_TRACKS;
        sector = rand() % findTotalSectorsOnDisk();
        sum += findAccessTime(track, sector, rotationsPM);
    }
    return sum/TRIALS;
}

//test access times
void testAccessTimes(){
    const int WIDTH_ONE = 10;
    const int WIDTH_TWO = 12;
    const int WIDTH_THREE = 22;
    const int DECIMALS = 6;

    cout << "TESTING: Access & Read Times" << endl;
    cout << "----------------------------" << endl;
    cout << "Now displaying time to [access and read] for some sectors for specific" << endl;
    cout << "[RPM], [start track #] and [target sector #]." << endl;

    cout << setw(WIDTH_ONE) << "RPM" << setw(WIDTH_ONE) << "Track" << setw(WIDTH_ONE) << "Sector" << setw(WIDTH_ONE) << "Time" << endl;

    int rotationsPM = 4000;
    const int MAX_RPM = 14000;
    const int RPM_INCREASE = 2000;
    int trackNum = 0;
    const int TRACK_INCREASE = 8;
    int sectorNum = 0;
    int totalSectors = findTotalSectorsOnDisk();
    const int SECTOR_INCREASE = 123;

    for (rotationsPM; rotationsPM <= MAX_RPM; rotationsPM += RPM_INCREASE){
        for (trackNum; trackNum <= TOTAL_TRACKS; trackNum += TRACK_INCREASE){
            for (sectorNum; sectorNum <= totalSectors; sectorNum += SECTOR_INCREASE){
                cout << setw(WIDTH_ONE) << rotationsPM << setw(WIDTH_ONE) << trackNum << setw(WIDTH_ONE) << sectorNum;
                cout << setw(WIDTH_ONE) << fixed << setprecision(DECIMALS) << findAccessTime(trackNum, sectorNum, rotationsPM) << endl;
            }
            sectorNum = 0;
        }
        trackNum = 0;
    }
    cout << endl;

    cout << "Now displaying access and read times" << endl;
    cout << setw(WIDTH_ONE) << "RPM" << setw(WIDTH_TWO) << "Read Time" << setw(WIDTH_THREE) << "Rand Read Time (*)" << endl;
    cout << fixed << setprecision(DECIMALS);

    int rotationsPM2 = 4000;
    const int MAX_RPM_2 = 15000;
    const int RPM_INCREASE_2 = 1000;
    for (rotationsPM2; rotationsPM2 <= MAX_RPM_2; rotationsPM2 += RPM_INCREASE_2){
        cout << setw(WIDTH_ONE) << rotationsPM2 << setw(WIDTH_TWO) << findAvgAccessReadTime(rotationsPM2) << setw(WIDTH_THREE) << findRandAvgAccessReadTime(rotationsPM2) << endl;
    }
    cout << "(*) = Values depend on random numbers so will change a little between runs." << endl << endl << endl;
}

//final display function
void hardDriveStats(){
    int rotationsPM = 0;
    const int ROTATION_MAX = 50000;
    const int ROTATION_MIN = 1;
    const int FIRST_TRACK = 0;
    const int FINAL_TRACK = TOTAL_TRACKS - 1;
    const int RPS_DECIMALS = 1;
    const int DECIMALS = 6;

    cout << "Enter HD rotations per minute (RPM): ";
    cin >> rotationsPM;

    while (rotationsPM > ROTATION_MAX || rotationsPM < ROTATION_MIN){
        cout << "Error: Value must be between 1 and 50000." << endl;
        cout << "Enter HD rotations per minute (RPM): ";
        cin >> rotationsPM;
    }
    cout << endl << endl;

    cout << fixed;
    cout << "Hard Drive Statistics:" << endl;
    cout << "----------------------" << endl;
    cout << "Number of tracks:             " << TOTAL_TRACKS << endl;
    cout << "Total number of sectors:      " << findTotalSectorsOnDisk() << endl;
    cout << "Revolutions per minute (RPM): " << rotationsPM << endl;
    cout << "Revolutions per second (RPS): " << setprecision(RPS_DECIMALS) <<findRotationsPS(rotationsPM) << endl;
    cout << "Rotational delay (seconds):   " << setprecision(DECIMALS) << findAvgRotDelay(rotationsPM) << endl;
    cout << "Time to read first sector:    " << findReadTime(FIRST_TRACK, rotationsPM) << " seconds" <<endl;
    cout << "Time to read last sector:     " << findReadTime(FINAL_TRACK, rotationsPM) << " seconds" << endl;
    cout << "Average read time:            " << findAvgAccessReadTime(rotationsPM) << " seconds" << endl;
    cout << "Average (random) read time:   " << findRandAvgAccessReadTime(rotationsPM) << " seconds" << endl;
}





