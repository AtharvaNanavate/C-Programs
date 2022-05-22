#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int rollNum;
    char name[20];
    float cgpa;
    struct node *left;
    struct node *right;
};

struct node *newNode(int num, char name[20], float cgpa)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->rollNum = num;
    strcpy(temp->name, name);
    temp->cgpa = cgpa;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int num, char name[20], float cgpa)
{

    if (root == NULL)
    {
        return newNode(num, name, cgpa);
    }

    if (num > root->rollNum)
    {
        root->right = insert(root->right, num, name, cgpa);
    }
    else if (num < root->rollNum)
    {
        root->left = insert(root->left, num, name, cgpa);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("\n-------------------------------------------------------------\n");
        printf("Roll Number : %d\n", root->rollNum);
        printf("Student Name : %s\n", root->name);
        printf("CGPA : %f\n", root->cgpa);
        printf("-------------------------------------------------------------");

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

    if (num > root->rollNum)
    {
        root->right = delete (root->right, num);
    }

    else if (num < root->rollNum)
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
            root->rollNum = iPre->rollNum;
            root->left = delete (root->left, iPre->rollNum);
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

struct node *searchNode(struct node *root, int num)
{
        
    if (root == NULL || root->rollNum == num)
    {
        
        return root;
    }
    if (root->rollNum > num)
    {
        
        searchNode(root->left, num);
    }
    else if (root->rollNum < num)
    {
        
        searchNode(root->right, num);
    }
}

int main()
{
    struct node *root = NULL;

    while (1)
    {
        int choice = 0;
        printf("\nMenu : \n");
        printf("1. Create a Classroom \n");
        printf("2. Add a student in your class \n");
        printf("3. Remove a student from your class \n");
        printf("4. Search for Student Information using Roll Number \n");
        printf("5. Display Roll Number wise information of all students in the class\n");
        printf("6. Display information of all students in the class in reverse order of Roll Number \n");
        printf("7. Exit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int num, n;
            char name[20];
            float cgpa;
            printf("\nEnter the total number of students in your class : ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                if (i == 1)
                {
                    printf("\nEnter Roll Number of the student : ");
                    scanf("%d", &num);

                    printf("Enter Name of the Student : ");
                    scanf("%s", name);

                    printf("Enter CGPA of the Student : ");
                    scanf("%f", &cgpa);
                    printf("\n");
                    root = newNode(num, name, cgpa);
                }
                else
                {
                    printf("Enter Roll Number of the student : ");
                    scanf("%d", &num);

                    printf("Enter Name of the Student : ");
                    scanf("%s", name);

                    printf("Enter CGPA of the Student : ");
                    scanf("%f", &cgpa);
                    printf("\n");
                    insert(root, num, name, cgpa);
                }
            }
        }

        else if (choice == 2)
        {
            int num;
            char name[20];
            float cgpa;
            printf("Enter Roll Number of the student : ");
            scanf("%d", &num);

            printf("Enter Name of the Student : ");
            scanf("%s", name);

            printf("Enter CGPA of the Student : ");
            scanf("%f", &cgpa);
            printf("\n");
            insert(root, num, name, cgpa);
        }

        else if (choice == 3)
        {
            int num;
            printf("Enter Roll Number of the student that you want to remove from your class: ");
            scanf("%d", &num);
            delete (root, num);
        }

        else if (choice == 4)
        {
            int roll;
            printf("\nEnter Roll Number of the Student : ");
            scanf("%d", &roll);
            struct node *res = searchNode(root, roll);
            if (res == NULL)
            {
                printf("There is no student in the class with this Roll Number.");
            }
            else
            {
                printf("\n-------------------------------------------------------------\n");
                printf("Roll Number : %d\n", res->rollNum);
                printf("Student Name : %s\n", res->name);
                printf("CGPA : %f\n", res->cgpa);
                printf("-------------------------------------------------------------");
            }
        }

        else if (choice == 5)
        {
            inorder(root);
            printf("\n");
        }

        else if (choice == 6)
        {
            mirrorImage(root);
            inorder(root);
            mirrorImage(root);
        }

        else
        {
            return 0;
        }
    }
}
