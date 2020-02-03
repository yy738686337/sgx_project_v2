#ifndef TYPES
#define TYPES
typedef enum{
    LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR, HARDTAN, LHTAN
}ACTIVATION;

typedef enum{
    SSE, MASKED, L1, SMOOTH, CE
} COST_TYPE;




#endif