typedef enum{
tank,assassin,soutien
}Type;

typedef struct {
    char nom[30];
    int degat;
} Attaque;


typedef struct {
    char nom[50];
    int pvc;
     int pvm;
    int defense;
    float agl;
    float vitess;
    Attaque att[2];
    Type type;
} Champion;

const char* lesroles(Type type) {
    switch (type) {
        case 0: return "tank";
        case 1: return "assassin";
        case 2: return "soutien";
        default: return "inconnu";
    }
}

 








