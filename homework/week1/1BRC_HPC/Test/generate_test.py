import random
import string

def generate_data(num_stations, num_records, filename, seed=42):
    random.seed(seed)
    
    station_names = [''.join(random.choices(string.ascii_uppercase, k=5)) for _ in range(num_stations)]
    with open(filename, 'w') as file:
        for station in station_names:
            for _ in range(num_records):
                temperature = random.uniform(-20, 40)
                file.write(f"{station}, {temperature:.1f}\n")

generate_data(3, 2, 'weather_data_test.csv')
#一个数据站1000个数据，共10000个数据
