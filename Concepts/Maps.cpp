#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

struct CityRecord {
	std::string Name;
	uint64_t Poulation;
	double Latitude, Longitude;

};

// to mamke it work on a custom type.
namespace std {
	template<>
	struct hash<CityRecord> {

		size_t operator()(const CityRecord& key) {
			return hash<std::string>()(key.Name);
		}

	};

}


int main() {

	std::vector<CityRecord> cityRecords;
	cityRecords.emplace_back("Melbourne", 500000, 2.4, 9.4);
	cityRecords.emplace_back("Berlin", 20000, 2.4, 9.4);
	cityRecords.emplace_back("Istanbul", 500000, 2.4, 9.4);


	std::map<std::string, CityRecord> cityMap;

	cityMap["Melbourne"] = CityRecord{ "Melbourne" , 50000 , 2.4 , 9.4};
	cityMap["Berlin"] = CityRecord{ "Berlin" , 20000 , 2.4 , 8.7 };


	CityRecord& berlindata = cityMap["Berlin"];
	std::cout << berlindata.Poulation << std::endl ;
	// traditonal method 
	/*for (auto& keyValue : cityMap) {
		std::string& name = keyValue.first;
		CityRecord& city = keyValue.second;
		std::cout << name << " : " << city << std::endl;
	}*/


	

}
