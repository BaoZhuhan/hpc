#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <time.h>
#include <fstream>

typedef struct Station {
    std::string name;
    double min_temp;
    double max_temp;
    double sum_temp;
    int count;
} Station;

bool compare( Station a, Station b ) {
    return a.name > b.name;
}

void load_data( const char* filename, std::vector<Station>& stations, int* num_stations ) {
    std::ifstream file( filename );
    if (!file) {
        perror( "Failed to open file" );
        exit( EXIT_FAILURE );
    }

    std::unordered_map<std::string, int> loc;

    std::string line;
    while (std::getline( file, line )) {
        std::string station_name = line.substr( 0, 5 );
        double temperature = std::stod( line.substr( 6 ) );

        if (loc.count( station_name ) > 0) {
            int index = loc[station_name];
            stations[index].min_temp = (temperature < stations[index].min_temp ? temperature : stations[index].min_temp);
            stations[index].max_temp = (temperature > stations[index].max_temp ? temperature : stations[index].max_temp);
            stations[index].sum_temp += temperature;
            stations[index].count++;
        }
        else {
            int index = *num_stations;
            loc[station_name] = index;
            Station now;
            now.count = 1;
            now.sum_temp = now.max_temp = now.min_temp = temperature;
            now.name = station_name;
            stations.push_back( now );
        }
    }

    file.close();
}

void print_statistics( std::vector<Station>& stations, int num_stations, FILE* out ) {
    for (int i = 0; i < num_stations; i++) {
        double mean = stations[i].sum_temp / stations[i].count;
        fprintf( out, "%s<%.1f/%.1f/%.1f>\n", (stations[i].name).c_str(), stations[i].min_temp, mean, stations[i].max_temp );
    }
}

int main() {
    std::vector<Station> stations;
    int num_stations = 0;

    /*clock*/
    struct timespec start, end;
    clock_gettime( CLOCK_MONOTONIC, &start );

    load_data( "weather_data_test.csv", stations, &num_stations );

    clock_gettime( CLOCK_MONOTONIC, &end );
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;

    FILE* output = fopen( "result.txt", "w" );
    if (output == NULL) {
        perror( "Failed to open output file" );
        return EXIT_FAILURE;
    }
    fprintf( output, "Data loading took %.3f seconds\n", elapsed_time );

    std::sort( stations.begin(), stations.end(), compare );
    print_statistics( stations, num_stations, output );

    fclose( output );

    return EXIT_SUCCESS;
}
