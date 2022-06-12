#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int num)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int num)
{

    if (root == NULL)
    {
        return newNode(num);
    }

    if (num > root->data)
    {
        root->right = insert(root->right, num);
    }
    else if (num < root->data)
    {
        root->left = insert(root->left, num);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

struct node *inorderPredecessor(struct node *root)
{
    struct node *node = root->left;
    
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

struct node *delete (struct node *root, int num)
{

    if (root == NULL)
    {
        return root;
    }

    if (num > root->data)
    {
        root->right = delete (root->right, num);
    }

    else if (num < root->data)
    {
        root->left = delete (root->left, num);
    }

    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            struct node *iPre = inorderPredecessor(root);
            root->data = iPre->data;
            root->left = delete (root->left, iPre->data);
            
            return root;
        }
    }
}

void mirrorImage(struct node *root)
{
    struct node *temp;
    if (root == NULL)
    {
        return;
    }
    else
    {
        mirrorImage(root->left);
        mirrorImage(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main()
{
    struct node *root = NULL;
    
    while (1)
    {
        int choice = 0;
        printf("Menu : \n");
        printf("1. Create a Binary Search Tree \n");
        printf("2. Insert an element into the Binary Search Tree \n");
        printf("3. Delete an element from the Binary Search Tree \n");
        printf("4. Print Inorder Traversal of the Binary Search Tree\n");
        printf("5. Mirror your Binary Search Tree\n");
        printf("6. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int num, n;
            printf("Enter the number of elements in your Binary Search Tree : ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                if (i == 1)
                {
                    printf("Enter the 1st element : ");
                    scanf("%d", &num);
                    root = newNode(num);
                }
                else
                {
                    printf("Enter the next element : ");
                    scanf("%d", &num);
                    insert(root, num);
                }
            }
        }

        else if (choice == 2)
        {
            int num;
            printf("Enter the number that you want to insert into the binary tree : ");
            scanf("%d", &num);
            insert(root, num);
        }

        else if (choice == 3)
        {
            int num;
            printf("Enter the number that you want to delete from the binary tree : ");
            scanf("%d", &num);
            delete (root, num);
        }

        else if (choice == 4)
        {
            inorder(root);
            printf("\n");
        }

        else if (choice == 5)
        {
            mirrorImage(root);
        }

        else
        {
            return 0;
        }
    }
}
