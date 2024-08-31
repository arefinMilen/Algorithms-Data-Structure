#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product
{
    char name[100];
    double price;
    int quantity;
    struct Product* next;
};
typedef struct Product product;

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

struct CartItem
{
    struct Product* product;
    int quantity;
    struct CartItem* next;
};
typedef struct CartItem cart;

product *productList = NULL;
cart *shoppingCart = NULL;

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

product* createProduct(char name[], double price, int quantity)
{
    product* newProduct = (product*)malloc(sizeof(product));
    if (newProduct == NULL)
    {
        return NULL;
    }
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->next = NULL;
    return newProduct;
}

void addProduct(product** productList, product* newProduct)
{
    if (newProduct == NULL)
    {
        printf("Error: Could not allocate memory for new product.\n");
        exit(1);
    }

    newProduct->next = *productList;
    *productList = newProduct;
}

void displayProducts(product* productList)
{
    product* current = productList;
    if (current == NULL)
    {
        printf("No products available.\n");
        return;
    }
    printf("Product List:\n");
    while (current != NULL)
    {
        printf("Name: %s, Price: $%.2lf, Quantity: %d\n", current->name, current->price, current->quantity);
        current = current->next;
    }
}

void searchProduct(product* productList, char searchName[])
{
    product* current = productList;
    while (current != NULL)
    {
        if (strcmp(current->name, searchName) == 0)
        {
            printf("Product found:\n");
            printf("Name: %s, Price: $%.2lf, Quantity: %d\n", current->name, current->price, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Product not found.\n");
}

void updateProductQuantity(product* productList, char productName[], int quantity)
{
    product* current = productList;
    while (current != NULL)
    {
        if (strcmp(current->name, productName) == 0)
        {
            current->quantity += quantity;
            return;
        }
        current = current->next;
    }
}

cart* createCartItem(product* product, int quantity)
{
    cart* newItem = (cart*)malloc(sizeof(cart));
    if (newItem == NULL)
    {
        return NULL;
    }
    newItem->product = product;
    newItem->quantity = quantity;
    newItem->product->price = product->price * quantity;
    newItem->next = NULL;
    return newItem;
}

void addToCart(cart** add_cart, product* product, int quantity)
{
    cart* newItem = createCartItem(product, quantity);
    newItem->next = *add_cart;
    *add_cart = newItem;
}

void displayCart(cart* add_cart)
{
    cart* current = add_cart;
    if (current == NULL)
    {
        printf("Your cart is empty.\n");
        return;
    }
    printf("Shopping Cart:\n");
    while (current != NULL)
    {
        printf("Name: %s, Price: $%.2lf, Quantity: %d\n", current->product->name, current->product->price, current->quantity);
        current = current->next;
    }
}

double calculateTotal(cart* add_cart)
{
    double total = 0.0;
    cart* current = add_cart;
    while (current != NULL)
    {
        total += (current->product->price * current->quantity);
        current = current->next;
    }
    return total;
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
            printf("\n\033[1m%40sCampusMart E-commerce Management System\033[0m\n", "");
            printf("%40s1. Add Product\n", "");
            printf("%40s2. Display Products\n", "");
            printf("%40s3. Search Product\n", "");
            printf("%40s4. Add to Cart\n", "");
            printf("%40s5. Display Cart\n", "");
            printf("%40s6. Checkout\n", "");
            printf("%40s7. Log Out\n", "");
            printf("%40s8. Exit\n", "");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1: ;// Add Product
                char productName[100];
                double productPrice;
                int productQuantity;

                printf("Enter product name: ");
                scanf("%s", productName);
                printf("Enter product price: ");
                scanf("%lf", &productPrice);
                printf("Enter product quantity: ");
                scanf("%d", &productQuantity);

                product* newProduct = createProduct(productName, productPrice, productQuantity);
                addProduct(&productList, newProduct);

                printf("Product added successfully!\n");
                break;
            case 2: // Display Products
                displayProducts(productList);
                break;
            case 3: // Search Product
                printf("Enter product name to search: ");
                scanf("%s", searchName);
                searchProduct(productList, searchName);
                break;
            case 4: ;// Add to Cart
                char cartProductName[100];
                int cartQuantity;

                printf("Enter product name to add to the cart: ");
                scanf("%s", cartProductName);
                printf("Enter quantity: ");
                scanf("%d", &cartQuantity);

                updateProductQuantity(productList, cartProductName, cartQuantity);
                struct Product* cartProduct = createProduct(cartProductName, productPrice, cartQuantity);
                addToCart(&shoppingCart, cartProduct, cartQuantity);

                printf("Product added to the cart successfully!\n");
                break;
            case 5: // Display Cart
                displayCart(shoppingCart);
                break;
            case 6: ;// Checkout
                double total = calculateTotal(shoppingCart);
                printf("Total amount: $%.2lf\n", total);
                printf("Checkout successful!\n");
                break;
            case 7: // Log Out
                loggedIn = 0;
                strcpy(currentUser, "");
                printf("You have been logged out.\n");
                break;
            case 8: // Exit
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}
