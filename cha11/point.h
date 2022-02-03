typedef struct {
    int x;
    int y;
} CPoint2DData;

typedef struct {
    int (*getX)(CPoint2DData * pData);
    int (*getY)(CPoint2DData * pData);
} CPoint2DFunc;

int getX(CPoint2DData * pData);

int getY(CPoint2DData * pData);

static int s_getX(CPoint2DData * pData);

static int s_getY(CPoint2DData * pData);

// extern int e_getX(CPoint2DData * pData);

// extern int e_getY(CPoint2DData * pData);

typedef struct {
    CPoint2DData * pData;
    CPoint2DFunc * pFunc;
} CPoint2D;

static CPoint2DData s_CPoint2DData = {1,-1};
static CPoint2DData * s_pCPoint2DData = &s_CPoint2DData;
static CPoint2DFunc s_CPoint2DFunc = {&getX,&getY};
static CPoint2DFunc * s_pCPoint2DFunc = &s_CPoint2DFunc;