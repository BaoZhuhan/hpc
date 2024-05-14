/*base on std::map */
/*time complexity : O(mlogn)*/

#include <bits/stdc++.h>
#include <string.h>
#include <time.h>

#define STATION_NUM 10005


typedef struct
{
    std::string name;
    double min_temp;
    double max_temp;
    double sum_temp;
    int count;
} Station;

/*比较函数*/
bool compare(Station a , Station b)
{
    return a.name > b.name;
}

/*加载数据*/
void load_data(const char *filename, Station stations[], int *num_stations)
{
    /*打开文件*/
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    std::map<std::string,int> loc;

    /*按行读入*/
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        char station_name_char[6];
        double temperature;
        sscanf(line, "%5s,%lf", station_name_char, &temperature);
        std::string station_name = station_name_char;
        
        if(loc.count(station_name) > 0){
            int index = loc[station_name];
            stations[index].min_temp = (temperature < stations[index].min_temp ? temperature : stations[index].min_temp);
            stations[index].max_temp = (temperature > stations[index].max_temp ? temperature : stations[index].max_temp);
            stations[index].sum_temp += temperature;
            stations[index].count++;
        }else{
            int index = *num_stations;
            loc[station_name] = index;
            stations[index].name = station_name;
            stations[index].min_temp = temperature;
            stations[index].max_temp = temperature;
            stations[index].sum_temp = temperature;
            stations[index].count = 1;
            (*num_stations)++;
        }
    }

    fclose(file);
}

/*计算函数*/
void print_statistics(const Station stations[], int num_stations, FILE *out)
{
    for (int i = 0; i < num_stations; i++)
    {
        double mean = stations[i].sum_temp / stations[i].count;
        fprintf(out, "%s<%.1f/%.1f/%.1f>\n", (stations[i].name).c_str(), stations[i].min_temp, mean, stations[i].max_temp);
    }
}

int main()
{
    Station stations[STATION_NUM];//结构数组
    int num_stations = 0;

    /*计时器*/
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    load_data("weather_data.csv", stations, &num_stations);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;

    FILE *output = fopen("result.txt", "w");
    if (output == NULL)
    {
        perror("Failed to open output file");
        return EXIT_FAILURE;
    }

    fprintf(output, "Data loading took %.3f seconds\n", elapsed_time);

    std::sort(stations, stations+num_stations , compare);
    print_statistics(stations, num_stations, output);

    fclose(output);

    return EXIT_SUCCESS;
}


