/*2151974 ��� ������*/

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    const char* q = str;
    if (p == NULL)
        return 0;
    while (*p != '\0')
        p++;
    return (int)(p - q);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* p;
    const char* q;
    p = s1;
    q = s2;
    if (p == NULL)
        return NULL;
    if (q == NULL)
        return s1;
    while (*p != '\0')
        p++;
    while (*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int n = len;
    char* p = s1;
    const char* q = s2;
    if (p == NULL)
        return NULL;
    if (q == NULL)
        return s1;
    if (len > tj_strlen(s2))
        n = tj_strlen(s2);
    while (*p != '\0')
        p++;
    while (n)
    {
        *p = *q;
        p++;
        q++;
        n--;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* p = s1;
    const char* q = s2;
    if (p == NULL)
        return NULL;
    if (q == NULL)
    {
        *p = '\0';
        return p;
    }
    while (*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    int n = len;
    char* p = s1;
    const char* q = s2;
    if (p == NULL)
        return NULL;
    if (q == NULL)
        return p;
    if (len > tj_strlen(s2))
        n = tj_strlen(s2);
    while (n)
    {
        *p = *q;
        p++;
        q++;
        n--;
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = s1;
    const char* q = s2;
    if (p == NULL && q == NULL)
        return 0;
    if (p == NULL)
        return -1;
    if (q == NULL)
        return 1;
    while (*p != '\0' && *q != '\0')
    {
        if (*p != *q)
            return *p - *q;
        p++;
        q++;
    }
    if (*p == '\0' && *q != '\0')
        return -*q;
    else if (*p != '\0' && *q == '\0')
        return *p;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = s1;
    const char* q = s2;
    if (p == NULL && q == NULL)
        return 0;
    if (p == NULL)
        return -1;
    if (q == NULL)
        return 1;
    while (*p != '\0' && *q != '\0')
    {
        if (*p == *q)
        {
            p++;
            q++;
            continue;
        }
        else
        {
            if (((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) &&
                ((*q >= 'a' && *q <= 'z') || (*q >= 'A' && *q <= 'Z')))
            {
                if (*p == *q || *p - *q == 'a' - 'A' || *p - *q == 'A' - 'a')
                {
                    p++;
                    q++;
                    continue;
                }
                else
                {
                    if (*p >= 'A' && *p <= 'Z')
                    {
                        if (*q >= 'A' && *q <= 'Z')
                            return *p - *q;
                        else
                            return *p - *q + 'a' - 'A';
                    }
                    else
                    {
                        if (*q >= 'a' && *q <= 'z')
                            return *p - *q;
                        else
                            return *p - *q - 'a' + 'A';
                    }
                }
            }
            else
            {
                if (*p >= 'A' && *p <= 'Z')
                    return *p - *q + 'a' - 'A';
                if (*q >= 'A' && *q <= 'Z')
                    return *p - *q - 'a' + 'A';
                return *p - *q;
            }
        }
    }
    if (*p == '\0' && *q != '\0')
    {
        if (*q >= 'A' && *q <= 'Z')
            return -*q - 'a' + 'A';
        else
            return -*q;
    }
    else if (*p != '\0' && *q == '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            return *p + 'a' - 'A';
        else
            return *p;
    }
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int n = len;
    const char* p = s1;
    const char* q = s2;
    if (p == NULL && q == NULL)
        return 0;
    if (p == NULL)
        return -1;
    if (q == NULL)
        return 1;
    if (len > (tj_strlen(s2)+1 > tj_strlen(s1)+1 ? tj_strlen(s1)+1 : tj_strlen(s2)+1))
        n = (tj_strlen(s2)+1 > tj_strlen(s1)+1 ? tj_strlen(s1)+1 : tj_strlen(s2)+1);
    while (n)
    {
        if (*p != *q)
            return *p - *q;
        p++;
        q++;
        n--;
    }
    if (*--p == '\0' && *--q != '\0')
        return -*q;
    else if (*--p != '\0' && *--q == '\0')
        return *p;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int n = len;
    const char* p = s1;
    const char* q = s2;
    if (p == NULL && q == NULL)
        return 0;
    if (p == NULL)
        return -1;
    if (q == NULL)
        return 1;
    if (len > (tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1))
        n = (tj_strlen(s2) + 1 > tj_strlen(s1) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1);
    while (n)
    {
        if (*p == *q)
        {
            p++;
            q++;
            n--;
            continue;
        }
        else
        {
            if (((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) &&
                ((*q >= 'a' && *q <= 'z') || (*q >= 'A' && *q <= 'Z')))
            {
                if (*p == *q || *p - *q == 'a' - 'A' || *p - *q == 'A' - 'a')
                {
                    p++;
                    q++;
                    n--;
                    continue;
                }
                else
                {
                    if (*p >= 'A' && *p <= 'Z')
                    {
                        if (*q >= 'A' && *q <= 'Z')
                            return *p - *q;
                        else
                            return *p - *q + 'a' - 'A';
                    }
                    else
                    {
                        if (*q >= 'a' && *q <= 'z')
                            return *p - *q;
                        else
                            return *p - *q - 'a' + 'A';
                    }
                }
            }
            else
            {
                if (*p >= 'A' && *p <= 'Z')
                    return *p - *q + 'a' - 'A';
                if (*q >= 'A' && *q <= 'Z')
                    return *p - *q - 'a' + 'A';
                return *p - *q;
            }
        }
    }
    if (*--p == '\0' && *--q != '\0')
    {
        if (*q >= 'A' && *q <= 'Z')
            return -*q - 'a' + 'A';
        else
            return -*q;
    }
    else if (*--p != '\0' && *--q == '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            return *p + 'a' - 'A';
        else
            return *p;
    }
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* p = str;
    if (p == NULL)
        return NULL;
    while (*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z')
            (*p) += 'A' - 'a';
        p++;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* p = str;
    if (p == NULL)
        return NULL;
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            (*p) += 'a' - 'A';
        p++;
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    if (p == NULL)
        return 0;
    while (*p != '\0')
    {
        if (*p == ch)
            return ++p - str;
        ++p;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    const char* q = substr;
    if (p == NULL || q == NULL)
        return 0;
    while (*p != '\0' && *q != '\0')
    {
        if (*p == *q)
        {
            p++;
            q++;
        }
        else
        {
            p = p - (q - substr) + 1;
            q = substr;
        }
    }
    if ((q - substr) == tj_strlen(substr))
        return p - (q - substr) + 1 - str;
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    if (p == NULL)
        return 0;
    while (*p != '\0')
        p++;
    p--;
    while (p >= str)
    {
        if (*p == ch)
            return ++p - str;
        --p;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    const char* q = substr;
    if (p == NULL || q == NULL)
        return 0;
    while (*p != '\0')
        p++;
    p--;
    while (*q != '\0')
        q++;
    q--;
    while (p - str != -1 && q - substr != -1)
    {
        if (*p == *q)
        {
            p--;
            q--;
        }
        else
        {
            p = p + tj_strlen(substr) - (q - substr) - 2;
            while (*q != '\0')
                q++;
            q--;
        }
    }
    if (q == substr - 1)
        return p - str + 2;
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* p = str, * q = str;
    if (p == NULL)
        return NULL;
    while (*q != '\0')
        q++;
    q--;
    while (p <= q)
    {
        char tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
    return str;
}
