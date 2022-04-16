### Homework 1 - task 1

## 1. Count how many lines are there in “data.dat”.
wc -l < data.dat
# < sends the contents of data.dat to the wc input channel

# -l, --lines
#         print the newline counts

## 2. Count how many lines of those contain “dolor” or “dalor”?
grep -c d[oa]lor data.dat
# -c, --count
#         Suppress normal output; instead print a count of matching lines for each input file.  With the -v, --invert-match option
#         (see below), count non-matching lines.

## 3. Count how many words are there in “data.dat”?
wc -w < data.dat

## 4. Count how many of those start with “mol”?
grep -c -o "\bmol\w*" data.dat
# -o, --only-matching
#         Print only the matched (non-empty) parts of a matching line, with each such part on a separate output line.

# \b matches a word boundary
# \w Matches any word character—that is, any letter, digit, or underscore: a-z, A-Z, 0-9, or _. Equivalent to [:word:].
# * more occurences of prev character
