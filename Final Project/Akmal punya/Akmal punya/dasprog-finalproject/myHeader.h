#define defaultItem {0 , "", 0, 0, 0, 0, 0};
typedef long long ll;

typedef struct
{
	int id;
	char name[101];
	int stock;
	ll price, capital, income;
	int transaction;
}itemData;

void delay(int n);
void dots(int len);
void divider();
void mainTitle();
void itemTitle();
void cashierTitle();
void reportTitle();
void itemMaster();
void option();
void addItem();
void deleteItem();

void editItems();
void addStock();

void reset(itemData *item);
void itemList();

void cashier();

void printStruct(ll sum, ll money);

void report();
