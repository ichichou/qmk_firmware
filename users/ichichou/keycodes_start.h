#if defined(ENABLE_MTGAP) && defined(ENABLE_BUNA)
#define MT_START (QK_USER  + 50)
#define BN_START (MT_START + 50)
#define KM_START (BN_START + 150)

#elif defined(ENABLE_MTGAP)
#define MT_START (QK_USER  + 50)
#define KM_START (MT_START + 50)

#elif defined(ENABLE_BUNA)
#define BN_START (QK_USER  + 50)
#define KM_START (BN_START + 150)

#endif
