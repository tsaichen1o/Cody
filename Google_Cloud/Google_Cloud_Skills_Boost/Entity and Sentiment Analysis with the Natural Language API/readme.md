Click Navigation menu > Compute Engine. You should see the provisioned linux instance, linux-instance, in the VM instances list.

Click on the SSH button. You will be brought to an interactive shell.

### Task 1. Create an API key

In the command line, enter in the following, replacing <YOUR_API_KEY> with the key you just copied:

```json
export API_KEY=<YOUR_API_KEY>
```
### Task 2. Make an entity analysis request

```json
nano request.json

{
  "document":{
    "type":"PLAIN_TEXT",
    "content":"Joanne Rowling, who writes under the pen names J. K. Rowling and Robert Galbraith, is a British novelist and screenwriter who wrote the Harry Potter fantasy series."
  },
  "encodingType":"UTF8"
}
```

The Natural Language API also supports sending files stored in Cloud Storage for text processing. If you wanted to send a file from Cloud Storage, you would replace `content` with `gcsContentUri` and give it a value of the text file's uri in Cloud Storage.

```json
curl "https://language.googleapis.com/v1/documents:analyzeEntities?key=${API_KEY}" \
  -s -X POST -H "Content-Type: application/json" --data-binary @request.json > result.json
```

### Task 3. Call the Natural Language API

```json
cat result.json
```

```json
student-00-e5da90ccbc79@linux-instance:~$ export API_KEY=AIzaSyAPzKKqD_kKemWMXyFXZUpTogrc_w27J1M
student-00-e5da90ccbc79@linux-instance:~$ nano request.json
student-00-e5da90ccbc79@linux-instance:~$ curl "https://language.googleapis.com/v1/documents:analyzeEntities?key=${API_KEY}" \
  -s -X POST -H "Content-Type: application/json" --data-binary @request.json > result.json
student-00-e5da90ccbc79@linux-instance:~$ cat result.json
{
  "entities": [
    {
      "name": "Joanne Rowling",
      "type": "PERSON",
      "metadata": {
        "wikipedia_url": "https://en.wikipedia.org/wiki/J._K._Rowling",
        "mid": "/m/042xh"
      },
      "salience": 0.79828626,
      "mentions": [
        {
          "text": {
            "content": "Joanne Rowling",
            "beginOffset": 0
          },
          "type": "PROPER"
        },
        {
          "text": {
            "content": "Rowling",
            "beginOffset": 53
          },
          "type": "PROPER"
        },
        {
          "text": {
            "content": "novelist",
            "beginOffset": 96
          },
          "type": "COMMON"
        },
        {
          "text": {
            "content": "Robert Galbraith",
            "beginOffset": 65
          },
          "type": "PROPER"
        }
      ]
    },
    {
      "name": "pen names",
      "type": "OTHER",
      "metadata": {},
      "salience": 0.07300248,
      "mentions": [
        {
          "text": {
            "content": "pen names",
            "beginOffset": 37
          },
          "type": "COMMON"
        }
      ]
    },
    {
      "name": "J.K.",
      "type": "PERSON",
      "metadata": {},
      "salience": 0.043804582,
      "mentions": [
        {
          "text": {
            "content": "J. K.",
            "beginOffset": 47
          },
          "type": "PROPER"
        }
      ]
    },
    {
      "name": "British",
      "type": "LOCATION",
      "metadata": {
        "wikipedia_url": "https://en.wikipedia.org/wiki/United_Kingdom",
        "mid": "/m/07ssc"
      },
      "salience": 0.019752095,
      "mentions": [
        {
          "text": {
            "content": "British",
            "beginOffset": 88
          },
          "type": "PROPER"
        }
      ]
    },
    {
      "name": "fantasy series",
      "type": "WORK_OF_ART",
      "metadata": {},
      "salience": 0.01764168,
      "mentions": [
        {
          "text": {
            "content": "fantasy series",
            "beginOffset": 149
          },
          "type": "COMMON"
        }
      ]
    },
    {
      "name": "Harry Potter",
      "type": "WORK_OF_ART",
      "metadata": {
        "mid": "/m/078ffw",
        "wikipedia_url": "https://en.wikipedia.org/wiki/Harry_Potter"
      },
      "salience": 0.014916742,
      "mentions": [
        {
          "text": {
            "content": "Harry Potter",
            "beginOffset": 136
          },
          "type": "PROPER"
        }
      ]
    },
    {
      "name": "screenwriter",
      "type": "PERSON",
      "metadata": {},
      "salience": 0.011085264,
      "mentions": [
        {
          "text": {
            "content": "screenwriter",
            "beginOffset": 109
          },
          "type": "COMMON"
        }
      ]
    }
  ],
  "language": "en"
}
student-00-e5da90ccbc79@linux-instance:~$ 
```

For each entity in the response, you get the entity type, the associated Wikipedia URL if there is one, the salience, and the indices of where this entity appeared in the text. Salience is a number in the [0,1] range that refers to the centrality of the entity to the text as a whole.

nano request.json

```json
 {
  "document":{
    "type":"PLAIN_TEXT",
    "content":"Harry Potter is the best book. I think everyone should read it."
  },
  "encodingType": "UTF8"
}
```

### Task 4. Sentiment analysis with the Natural Language API

Next you send the request to the API's analyzeSentiment endpoint:

```json
curl "https://language.googleapis.com/v1/documents:analyzeSentiment?key=${API_KEY}" \
  -s -X POST -H "Content-Type: application/json" --data-binary @request.json
```

`score` - is a number from -1.0 to 1.0 indicating how positive or negative the statement is.
`magnitude` - is a number ranging from 0 to infinity that represents the weight of sentiment expressed in the statement, regardless of being positive or negative.

### Task 5. Analyzing entity sentiment

```json

curl "https://language.googleapis.com/v1/documents:analyzeEntitySentiment?key=${API_KEY}" \
  -s -X POST -H "Content-Type: application/json" --data-binary @request.json
```

### Task 6. Analyzing syntax and parts of speech
```json
curl "https://language.googleapis.com/v1/documents:analyzeSyntax?key=${API_KEY}" \
  -s -X POST -H "Content-Type: application/json" --data-binary @request.json
```

partOfSpeech tells you that "Joanne" is a noun.
dependencyEdge includes data that you can use to create a dependency parse tree of the text. Essentially, this is a diagram showing how words in a sentence relate to each other. A dependency parse tree for the sentence above would look like this:

![Alt text](image.png)

`headTokenIndex` is the index of the token that has an arc pointing at "Joanne". Think of each token in the sentence as a word in an array.
`headTokenIndex` of 1 for "Joanne" refers to the word "Rowling", which it is connected to in the tree. The label NN (short for noun compound modifier) describes the word's role in the sentence. "Joanne" modifies "Rowling", the subject of the sentence.
`lemma` is the canonical form of the word. For example, the words run, runs, ran, and running all have a lemma of run. The lemma value is useful for tracking occurrences of a word in a large piece of text over time.

### Task 7. Multilingual natural language processing
```json
{
  "document":{
    "type":"PLAIN_TEXT",
    "content":"日本のグーグルのオフィスは、東京の六本木ヒルズにあります"
  }
}
```
```json
curl "https://language.googleapis.com/v1/documents:analyzeEntities?key=${API_KEY}" \
  -s -X POST -H "Content-Type: application/json" --data-binary @request.json
```

