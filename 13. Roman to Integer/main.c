int romanToInt(char * s){int map[171];map[0] = 0;map[1] = 0;map['I'] = 1; map['V'] = 5;map['X'] = 10;map['L'] = 50;map['C'] = 100;map['D'] = 500;map['M'] = 1000;for(map[1]=0; *(s+map[1]) != '\0'; map[1]++){map[2] = map[*(s+map[1])];int nextNumber = 0;*(s+map[1]+1) ? (nextNumber = map[*(s+map[1]+1)]) :( nextNumber = 0);if(nextNumber > 0){if(nextNumber > map[2]){map[2] = nextNumber - map[2];map[1]++;}}map[0]+=map[2];nextNumber = 0;}return map[0];}