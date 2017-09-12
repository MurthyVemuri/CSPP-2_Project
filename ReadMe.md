Bag of Words:

In this method you have to compute a distance (an angle) between two given documents or between two strings using the cosine similarity metric. You start with reading in the text and counting frequency of each word. The word frequency distribution for the text D is Java's Map from words to their frequency counts, which we'll denote as freq(D) . We view freq(D) as a vector of nonnegative integers in N-dimensional space. For example, reading the string "To be or not to be" results in the following map {be=2, not=1, or=1, to=2}

These 4 distinct words make a document representation as a 4-dimensional vector {2, 1, 1, 2} in term space. A word is a sequence of letters [a..zA..Z] that might include digits [0..9] and the underscore character. All delimiters are thrown away and not kept as part of the word. Here are examples of words: abcd abcd12 abc_ a12cd 15111

We'll treat all upper-case letters as if they are lower-case, so that "CMU" and "cmu" are the same word. The Euclidean norm of the frequency vector is defined by ||x|| = sqrt(x1^2+x2^2+....+xn^2) where xk denote frequencies for each word in the text. For the above example, the norm is ||x|| = sqrt(2^2+1^2+1^2+2^2) = 3.16228 The Dot product (or the inner product) of two frequency vectors X and Y is defined by X = {x1,x2,x3,...,xn}; Y = {y1,y2,y3,...,yn} X . Y = x1.y1+x2.y2+...+xn.yn Here we multiply frequencies xk and yk of the same word in both text documents. Finally, we define a distance between two documents D1 and D2 by using cosine similarity measurement:

Observe, the distance between two identical documents is 0, and the distance is Pi/2 = 1.57... if two documents have no common words.

dist(D1,D2) = arccos(freq(D1) . freq(D2) / ||freq(D1)|| * ||freq(D2)||)

Please read from the following URL. https://www.andrew.cmu.edu/course/15-121/labs/HW-4%20Document%20Distance/lab.html

Expected output: If there is plagiarism, most words that are used in text will match. There will be significant similarities with frequencies as well.

Example: File - 1 Content: To be or not to be File - 2 Content: Doubt truth to be a liar

The words from both the files are as follows.

Note: Freq(X) is : Frequency of words from file x

Words Freq(file 1) Freq(file 2) Dot product of (Freq(File1) and Freq(File 2)) To 2 1 2 Be 2 1 2 Or 1 0 0 Not 1 0 0 Doubt 0 1 0 Truth 0 1 0 A 0 1 0 Liar 0 1 0

The Euclidean norm of the frequency vector is as follows: || File 1 || is: sqrt(10) || File 2 || is:sqrt( 6)

So, the similarity between the documents are

Similarity Function = cos θ = Dot Product(Frequency of File 1, Frequency of File 2) / ||File 1|| * || File 2||

So, you will get, cos θ = 4 / (sqrt (10) * sqrt(6) )= 0.516 which is 51.6% matching

Limitations: This method is inefficient for long documents, because order in which these terms appear is lost. Given any topic there are certain words that are bound of appear which make this method informal. This method results in both false positive and false negative which is not representing actual copied document and not identifying a copied document. This method will not identify cases where central idea is copied with use of different words. String matching: In this method every text document is checked for common sub strings with the verifying document. Although this method is computationally expensive finding longest common substring will tell us what % or how many sentences are copied from the verifying document. This method relies on patterns, and text overlaps.

Example: File - 1 Content: what is your name File - 2 Content: my name is xyz

In Computer Science, brute-force search or exhaustive search, also known as generate and test, is a very general problem-solving technique that consists of systematically enumerating all possible candidates for the solution and checking whether each candidate satisfies the problem's statement.

Step1: what is your name my name is xyz w and m does not match so we shift the string to next position(word), until we find a match.

Step2: what is your name my name is xyz Now, we can see is and is matches. So, LCS = 2 and we continue the iteration. . . StepN: what is your name my name is xyz Now, LCS changes to 4 Length of LCS is 4 Total length of file1 and file2 is 31
%match = ((4 * 2) / 31) * 100 = 25%

Expected output: If there is plagiarism, longest common substring will have large portions of verifying documents. It is possible that we may find other sentences as well that were copied. Limitations: This method is computationally expensive in terms of time and space. Most string matching problems use effective algorithms and data structures that were not part of CSPP1 as a result you will end up using brute force (naive) method which is costly and ineffective.
