#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char username[50];
    char password[50];
    struct User* next;
};
typedef struct User user;
user* userList = NULL;

user* createUser(char username[], char password[]);
void addUser(user** userList, user* newUser);
int authenticateUser(user* userList, char username[], char password[]);

struct Product
{
    char name[100];
    char brand[100];
    int price;
    struct Product* next;
} *head;
typedef struct Product product;

void add_product();
void display_products();
void delete_products();

struct sell_products
{
    char name[100];
    struct sell_products *next;
};
typedef struct sell_products sell_product;
sell_product *top=NULL;

void add_cart();
void display_cart();
void search_buying_product();
void delete_cart();

void add_product()
{
    int num;
    printf("Enter number of products you want to add: ");
    scanf("%d", &num);
    head = (product*)malloc(sizeof(product));
    printf("Enter details for product 1:\n");
    printf("Name: ");
    scanf(" %99[^\n]", head->name);
    printf("\nBrand: ");
    scanf(" %99[^\n]", head->brand);
    printf("\nPrice: ");
    scanf("%d", &head->price);
    head->next = NULL;

    product* new_product, * temp;
    temp = head;
    for (int i = 2; i <= num; i++)
    {
        new_product = (product*)malloc(sizeof(product));
        printf("\nEnter details for product %d:\n", i);
        printf("Name: ");
        scanf(" %99[^\n]", new_product->name);
        printf("\nBrand: ");
        scanf(" %99[^\n]", new_product->brand);
        printf("\nPrice: ");
        scanf("%d", &new_product->price);

        new_product->next = NULL;
        temp->next = new_product;
        temp = temp->next;
    }
}

void display_products()
{
    product *temp;
    temp = head;
    int i = 1;

    if (temp == NULL)
    {
        printf("\nYour Product List is Empty.\n");
        return;
    }

    printf("\nYour Product List: \n");
    while (temp != NULL)
    {
        printf("\n%d.\n", i);
        printf("Name: %-20sBrand: %-20sPrice: %d", temp->name, temp->brand, temp->price);
        i++;
        temp = temp->next;
    }
}

product *head = NULL;


void delete_begin();
void delete_middle();
void delete_end();

int isListEmpty()
{
    return head == NULL;
}

void delete_products()
{
    if (isListEmpty())
    {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    int choice;
    printf("From where you want to delete your product: \n");
    printf("1. First Product\n2. Random Product\n3. Last Product\n4. Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        delete_begin();
        break;
    case 2:
        delete_middle();
        break;
    case 3:
        delete_end();
        break;
    case 4:
        exit(0);
    default:
        printf("Enter a valid number.\n");
    }
}

void delete_begin()
{
    product *temp = head;
    head = temp->next;
    free(temp);
    printf("Product deleted from the beginning.\n");
}

void delete_middle()
{
    int n;
    printf("Enter number from where you want to delete product: ");
    scanf("%d", &n);

    if (isListEmpty())
    {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    product *temp = head;
    product *prev = NULL, *current = NULL;

    for (int i = 1; i < n && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds. No product deleted.\n");
        return;
    }

    current = temp->next;

    if (prev == NULL)
    {
        head = current;
    }
    else
    {
        prev->next = current;
    }

    free(temp);
    printf("Product deleted from position %d.\n", n);
}

void delete_end()
{
    if (isListEmpty())
    {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    product *temp = head;
    product *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        head = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    free(temp);
    printf("Product deleted from the end.\n");
}

void search_product()
{
    char nam[100];
    printf("Enter product name you want to search: ");
    scanf("%s", nam);

    product *temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (strcmp(temp->name, nam) == 0)
        {
            printf("Your product found at list %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Your product is not found in the list.\n");
}

void add_cart()
{
    int num;
    printf("Enter number of products to add to the cart: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        sell_product *new_product;
        new_product = (sell_product *)malloc(sizeof(sell_product));
        if (new_product == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("\nEnter product details for product %d:\n", i + 1);
        printf("Name: ");
        scanf(" %49[^\n]", new_product->name);

        new_product->next = top;
        top = new_product;
    }

    printf("Products added to the cart successfully.\n");
}

void display_cart()
{
    sell_product *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Your bag is empty\n");
    }
    else
    {
        printf("Your buying products: \n");
        while (temp != NULL)
        {
            printf("|%s|\n", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }

}

void search_buying_product()
{
    char name[50];
    printf("Enter product name for search: ");
    scanf("%s", name);

    sell_product *temp = top;
    int position = 1;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("\nYour desire product %s found at position %d in the stack.\n", name, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("\nYour product %s not found in the stack.\n", name);
}

void delete_cart()
{
    sell_product *temp;
    temp = top;
    if (temp == NULL)
    {
        printf("Nothing to delete.\n");
    }
    else
    {
        printf("I want to delete my buying last product.\n");
        printf("Popped Product: %s\n", temp->name);
        top = top->next;
        free(temp);
    }
}

user* createUser(char username[], char password[])
{
    user* newUser = (user*)malloc(sizeof(user));
    if (newUser == NULL)
    {
        printf("Error: Could not allocate memory for new user.\n");
        exit(1);
    }
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = NULL;
    return newUser;
}

void addUser(user** userList, user* newUser)
{
    newUser->next = *userList;
    *userList = newUser;
}

int authenticateUser(user* userList, char username[], char password[])
{
    user* current = userList;
    while (current != NULL)
    {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main()
{
    int loggedIn = 0;
    char currentUser[50] = "";

    int choice;
    char searchName[100];

    while(1)
    {
        if(!loggedIn)
        {
            char title[]="Welcome to our CampusMart";
            printf("\033[1m%60s\033[0m\n", title);
            printf("%40s1. Sign Up\n", "");
            printf("%40s2. Log In\n", "");
            printf("%40s3. Exit\n", "");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
            case 1:
                ;
                char newUsername[50], newPassword[50];
                printf("Enter a username: ");
                scanf("%s", newUsername);
                printf("Enter a password: ");
                scanf("%s", newPassword);
                user* newUser = createUser(newUsername, newPassword);
                addUser(&userList, newUser);
                printf("Account created successfully!\n");
                break;

            case 2:
                if (loggedIn)
                {
                    printf("You are already logged in as %s.\n", currentUser);
                }
                else
                {
                    char loginUsername[50], loginPassword[50];
                    printf("Enter your username: ");
                    scanf("%s", loginUsername);
                    printf("Enter your password: ");
                    scanf("%s", loginPassword);

                    if (authenticateUser(userList, loginUsername, loginPassword))
                    {
                        loggedIn = 1;
                        strcpy(currentUser, loginUsername);
                        printf("Welcome, %s!\n", currentUser);
                    }
                    else
                    {
                        printf("Authentication failed. Please check your credentials.\n");
                    }
                }
                break;
            case 3:
                printf("\033[1m%40sGoodbye!\033[0m\n", "");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }

        }
        else
        {
            while(1)
            {
                printf("\n\033[1m%35sCampusMart E-commerce Management System\033[0m\n", "");
                printf("%40s1. Add Products from seller\n", "");
                printf("%40s2. Delete Products from seller\n", "");
                printf("%40s3. Display Products for seller\n", "");
                printf("%40s4. Search Product for seller\n", "");
                printf("%40s5. Add to cart for seller\n", "");
                printf("%40s6. Display cart for seller\n", "");
                printf("%40s7. Search Products for seller\n", "");
                printf("%40s8. Delete Products from cart\n", "");
                printf("%40s9. Log Out\n", "");
                printf("%40s10. Exit\n", "");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                case 1:
                    add_product();
                    break;
                case 2:
                    delete_products();
                    break;
                case 3:
                    display_products();
                    break;
                case 4:
                    search_product();
                    break;
                case 5:
                    add_cart();
                    break;
                case 6:
                    display_cart();
                    break;
                case 7:
                    search_buying_product();
                    break;
                case 8:
                    delete_cart();
                    break;
                case 9:
                    loggedIn = 0;
                    strcpy(currentUser, "");
                    printf("You have been logged out.\n");
                    break;
                case 10:
                    printf("%40sGoodbye!\n", "");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
                }
            }
        }
    }
    return 0;
}
