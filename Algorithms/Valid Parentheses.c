/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/****************************************************************************************/

struct stack
{
    char ch;
    struct stack*  next;
    struct stack*  prev;
};

bool isValid(char* s) {
    struct stack head, oth, *last = &head, *othlast = &oth;
    head.ch = oth.ch = 0x00;
    head.next = oth.next = NULL;
    head.prev = oth.prev = NULL;
    
    for (int i = 0; i< strlen(s); i++)
    {
        switch (s[i])
        {
            case '(':
            case '[':
            case '{':
            {
                last->next = (struct stack*)malloc(sizeof(struct stack));
                last->next->prev = last;
                last = last->next;
                last->next = NULL;
                last->ch = s[i];
            }break;
            case ')':
            {
                if (last->ch == '(')
                {
                    last = last->prev;
                    free(last->next);
                    last->next = NULL;
                }
                else
                {
                    othlast->next = (struct stack*)malloc(sizeof(struct stack));
                    othlast->next->prev = othlast;
                    othlast = othlast->next;
                    othlast->next = NULL;
                    othlast->ch = s[i];
                }
            }break;
            case ']':
            {
                if (last->ch == '[')
                {
                    last = last->prev;
                    free(last->next);
                    last->next = NULL;
                }
                else
                {
                    othlast->next = (struct stack*)malloc(sizeof(struct stack));
                    othlast->next->prev = othlast;
                    othlast = othlast->next;
                    othlast->next = NULL;
                    othlast->ch = s[i];
                }
            }break;
            case '}':
            {
                if (last->ch == '{')
                {
                    last = last->prev;
                    free(last->next);
                    last->next = NULL;
                }
                else
                {
                    othlast->next = (struct stack*)malloc(sizeof(struct stack));
                    othlast->next->prev = othlast;
                    othlast = othlast->next;
                    othlast->next = NULL;
                    othlast->ch = s[i];
                }
            }break;
            default:break;
        }
    }
    
    if ((NULL == head.next) && (NULL == oth.next))
    {
        return true;
    }
    else
    {
        return false;
    }
}