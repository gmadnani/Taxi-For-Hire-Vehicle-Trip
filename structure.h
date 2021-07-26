/***************************************************************************/
//MAIN Structure
/***************************************************************************/
#define MAX_INT 128
#define MAX_LINE 256

struct Record {
    char VendorID[MAX_INT];
    char passenger_count[MAX_INT];
    char trip_distance[MAX_INT];
    char RatecodeID[MAX_INT];
    char store_and_fwd_flag[MAX_INT];
    char PULocationID[MAX_INT];
    char DOLocationID[MAX_INT];
    char payment_type[MAX_INT];
    char fare_amount[MAX_INT];
    char extra[MAX_INT];
    char mta_tax[MAX_INT];
    char tip_amount[MAX_INT];
    char tolls_amount[MAX_INT];
    char improvement_surcharge[MAX_INT];
    char total_amount[MAX_INT];
    char PUdatetime[MAX_INT];
    char DOdatetime[MAX_INT];
    char trip_duration[MAX_INT];
    struct Record *right;
    struct Record *left;
    struct Record *next;
};

typedef struct Record record;

/*****************************************************************************/
