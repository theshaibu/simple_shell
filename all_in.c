#include "shell.h"

/**
 * swap_char - Replaces specific characters in the input string for internal processing.
 * @input: Input string.
 * @bool: Flag for swapping or reverting characters.
 * Return: Modified input string.
 */
char *swap_char(char *input, int bool) {
    int i;

    if (bool == 0) {
        for (i = 0; input[i]; i++) {
            if (input[i] == '|') {
                if (input[i + 1] != '|')
                    input[i] = 16;
                else
                    i++;
            }

            if (input[i] == '&') {
                if (input[i + 1] != '&')
                    input[i] = 12;
                else
                    i++;
            }
        }
    } else {
        for (i = 0; input[i]; i++) {
            input[i] = (input[i] == 16 ? '|' : input[i]);
            input[i] = (input[i] == 12 ? '&' : input[i]);
        }
    }
    return (input);
}

/**
 * add_nodes - Processes the input string, identifies separators, and creates nodes for lines and separators in linked lists.
 * @head_s: Pointer to the head of the separator list.
 * @head_l: Pointer to the head of the line list.
 * @input: Input string.
 * Return: Modified linked lists.
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input) {
    int i;
    char *line;

    input = swap_char(input, 0);

    for (i = 0; input[i]; i++) {
        if (input[i] == ';')
            add_sep_node_end(head_s, input[i]);

        if (input[i] == '|' || input[i] == '&') {
            add_sep_node_end(head_s, input[i]);
            i++;
        }
    }

    line = _strtok(input, ";|&");
    do {
        line = swap_char(line, 1);
        add_line_node_end(head_l, line);
        line = _strtok(NULL, ";|&");
    } while (line != NULL);
}

/**
 * go_next - Updates separator and line list pointers based on the execution status.
 * @list_s: Pointer to the separator list.
 * @list_l: Pointer to the line list.
 * @datash: Data structure for shell.
 * Return: Modified pointers.
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash) {
    int loop_sep;
    sep_list *ls_s;
    line_list *ls_l;

    loop_sep = 1;
    ls_s = *list_s;
    ls_l = *list_l;

    while (ls_s != NULL && loop_sep) {
        if (datash->status == 0) {
            if (ls_s->separator == '&' || ls_s->separator == ';')
                loop_sep = 0;
            if (ls_s->separator == '|')
                ls_l = ls_l->next, ls_s = ls_s->next;
        } else {
            if (ls_s->separator == '|' || ls_s->separator == ';')
                loop_sep = 0;
            if (ls_s->separator == '&')
                ls_l = ls_l->next, ls_s = ls_s->next;
        }
        if (ls_s != NULL && !loop_sep)
            ls_s = ls_s->next;
    }

    *list_s = ls_s;
    *list_l = ls_l;
}

/**
 * split_commands - Orchestrates the parsing and execution of multiple commands separated by ;, |, or &.
 * @datash: Data structure for shell.
 * @input: Input string.
 * Return: 0 if the loop should be terminated, 1 otherwise.
 */
int split_commands(data_shell *datash, char *input) {
    sep_list *head_s, *list_s;
    line_list *head_l, *list_l;
    int loop;

    head_s = NULL;
    head_l = NULL;

    add_nodes(&head_s, &head_l, input);

    list_s = head_s;
    list_l = head_l;

    while (list_l != NULL) {
        datash->input = list_l->line;
        datash->args = split_line(datash->input);
        loop = exec_line(datash);
        free(datash->args);

        if (loop == 0)
            break;

        go_next(&list_s, &list_l, datash);

        if (list_l != NULL)
            list_l = list_l->next;
    }

    free_sep_list(&head_s);
    free_line_list(&head_l);

    if (loop == 0)
        return (0);
    return (1);
}

/**
 * split_line - Tokenizes the input string into an array of strings.
 * @input: Input string.
 * Return: Array of strings (tokens).
 */
char **split_line(char *input) {
    size_t bsize;
    size_t i;
    char **tokens;
    char *token;

    bsize = TOK_BUFSIZE;
    tokens = malloc(sizeof(char *) * (bsize));
    if (tokens == NULL) {
        write(STDERR_FILENO, ": allocation error\n", 18);
        exit(EXIT_FAILURE);
    }

    token = _strtok(input, TOK_DELIM);
    tokens[0] = token;

    for (i = 1; token != NULL; i++) {
        if (i == bsize) {
            bsize += TOK_BUFSIZE;
            tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
            if (tokens == NULL) {
                write(STDERR_FILENO, ": allocation error\n", 18);
                exit(EXIT_FAILURE);
            }
        }
        token = _strtok(NULL, TOK_DELIM);
        tokens[i] = token;
    }

    return (tokens);
}
