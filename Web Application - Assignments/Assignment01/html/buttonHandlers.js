/*
Deneo Shi 101271921

added functions:

handleTransposeUp()
handleKeyDown()
findInTransposition()
includedInTransposition()
getTransposed()
getTransposedDown()

NOTE: all definitions and explanations of the functions are written below (before the functions)

ex:
//description of a function()
the function()

*/

//KEY CODES
//should clean up these hard coded key codes
const ENTER = 13
const RIGHT_ARROW = 39
const LEFT_ARROW = 37
const UP_ARROW = 38
const DOWN_ARROW = 40



//did not change
function handleKeyDown(e) {

  //console.log("keydown code = " + e.which );
  let keyCode = e.which
  if (keyCode == UP_ARROW | keyCode == DOWN_ARROW) {
    //prevent browser from using these with text input drop downs
    e.stopPropagation()
    e.preventDefault()
  }

}

//did not change
function handleKeyUp(e) {
  //console.log("key UP: " + e.which);
  if (e.which == RIGHT_ARROW | e.which == LEFT_ARROW | e.which == UP_ARROW | e.which == DOWN_ARROW) {
    //do nothing for now
  }

  if (e.which == ENTER) {
    handleSubmitButton() //treat ENTER key like you would a submit

    document.getElementById('userTextField').value = ''
  }

  e.stopPropagation()
  e.preventDefault()

}

//did not change
function handleSubmitButton() {

  //get text from user text input field
  let userText = document.getElementById('userTextField').value
  //clear lines of text in textDiv
  let textDiv = document.getElementById("text-area")
  textDiv.innerHTML = ''

  if (userText && userText !== '') {
    let userRequestObj = {
      text: userText
    }
    let userRequestJSON = JSON.stringify(userRequestObj)
    //clear the user text field
    document.getElementById('userTextField').value = ''
    //alert ("You typed: " + userText);

    let xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function () {
      if (this.readyState == 4 && this.status == 200) {
        console.log("typeof: " + typeof this.responseText)
        console.dir(this.responseText)
        //we are expecting the response text to be a JSON string
        let responseObj = JSON.parse(this.responseText)
        console.dir(responseObj)

        words = [] //clear drag-able words array;
        if (responseObj.songLines) {
          song.songLines = responseObj.songLines
          transposedByNSemitones = 0 //reset transpose to no-transpose
          parseChordProFormat(song.songLines)
        }

      }
    }
    xhttp.open("POST", "song") //API .open(METHOD, URL)
    xhttp.send(userRequestJSON) //API .send(BODY)

  }

}


/*
new function ---
Name: handleTransposeUp
Action: once click "Transpose Up", this function will do
1. modify pre-existing counter (counts how many times the "Transpose Up" button is clicked)
2. Create arrays, read the "strings" from pre-existing html page ("text-area"), and input these strings into the arrays
3. Clear the html "textDiv" area
4. the for loop:
  4.01: newChords: is an array that has no '' (empty) strings of chord
  4.02: translatedChords: is an array that has all chords that have been Transposed (by transpositions)
  4.03: unique: is an array that holds all unique chords from newChords (acting like a <Set>: 1 element/chord only appears once)
5. print out onto the console
6. print out onto the hmtl page (textDiv): make use of pre-existing counter (and if the counter is a multiple of 12), then print them out as Green, otherwise, red
*/
function handleTransposeUp() {

  // (Step 1)
  let counter = document.getElementById('myCounter').value;

  counter = parseInt(counter);

  counter++;
  document.getElementById('myCounter').value = counter;

  // (Step 2)
  //initialize arrays
  let resultLyrics = [];
  let resultChords = [];
  let matchesLyric = document.querySelectorAll("#text-area p");
  let matcheschord = document.querySelectorAll("#text-area .chord");
  //  console.log(matches);
  for (var i = 0, l = matchesLyric.length; i < l; i++)
    resultLyrics[i] = matchesLyric[i].innerText;

  for (var i = 0, l = matcheschord.length; i < l; i++)
    resultChords[i] = matcheschord[i].textContent;


  // (Step 3)
  let textDiv = document.getElementById("text-area");

  textDiv.innerHTML = '';



  // (Step 4)
  for (let i = 0; i < resultChords.length; i++) {

    let newChords = [];
    let translatedChords = [];
    let unique = [];

    // (Step 4.1)
    newChords = resultChords[i].split(/\s+/);
    newChords = newChords.filter(Boolean);//remove empty elements from newChords
    for (let x = 0; x < newChords.length; x++) {
      if (!unique.includes(newChords[x])) {
        unique.push(newChords[x]);
      }
    }

    // (Step 4.2) and (Step 4.3)
    let testCount = 0;

    for (let y = 0; y < unique.length; y++) {
      let uniqueY = unique[y];

      // for chords that have a length of >=2
      if (unique[y].length >= 2) {

        // only take the first 2 letters of the chord (and find it)
        let first2C = unique[y].slice(0, 2);

        //check if the first 2 characters of the chord can be found inside the Transpositions (ex: Bb can be found)
        let arrFound = findInTransposition(Transpositions, first2C);

        if(arrFound[0]){

          // check if it equals
          let transpoWithSuffix = getTransposed(Transpositions, arrFound[1], arrFound[2], unique[y]);
          translatedChords.push(transpoWithSuffix);
        }

        // (ex: B7 will go here: B7 length >= 2, but B7 is not a chord inside the Transpositions)
        else {
          //check if it includes
          let arrInc = includedInTransposition(Transpositions, first2C);
          if(arrInc[0]){
            let transpoWithSuffix = getTransposed(Transpositions, arrInc[1], arrInc[2], unique[y]);
            translatedChords.push(transpoWithSuffix);
          }
        }
      }

      // if the length of the initial chord is 1 (ex: B)
      if (uniqueY.length == 1) {

        let arrInc1= findInTransposition(Transpositions, uniqueY);

        if(arrInc1[0]){

          let transpoWithSuffix = getTransposed(Transpositions, arrInc1[1], arrInc1[2], uniqueY);
          translatedChords.push(transpoWithSuffix);
        }
      }
    }//end y-index

    // translate
    let aaaa = '';
    let aa = '';

    for (let w = 0; w < unique.length; w++) {

      let re = new RegExp(`${unique[w]}($|\\s)`, "g");

      if (aa == '') {
        aa = resultChords[i].replace(re, translatedChords[w] + ' ');
      }
      else {
        aaaa = aa.replace(re, translatedChords[w] + ' ');
        aa = aaaa;
      }
    }

    // (Step 5)
    console.log('');
    console.log(aa);
    console.log(resultLyrics[i]);

    // (Step 6)
    if (aa == '') {
      aa = "&nbsp;";
    }
    if (parseInt(document.getElementById("myCounter").value) % 12 == 0) {
      textDiv.innerHTML += `<span class=${'chord'}>${aa}</span>`;
    }
    else{
      textDiv.innerHTML += `<span class=${'chord'} style="color:red">${aa}</span>`;
    }

    aa = ''
    textDiv.innerHTML += `<p> ${resultLyrics[i]}</p>`;

  } //end forloop resultChords[i]


}// end function



/*
new function ---
Name: handleTransposeDown
Action: once click "Transpose Down", this function will do
1. modify pre-existing counter (counts how many times the "Transpose Down" button is clicked)
2. Create arrays, read the "strings" from pre-existing html page ("text-area"), and input these strings into the arrays
3. Clear the html "textDiv" area
4. the for loop:
  4.01: newChords: is an array that has no '' (empty) strings of chord
  4.02: translatedChords: is an array that has all chords that have been Transposed (by transpositions)
  4.03: unique: is an array that holds all unique chords from newChords (acting like a <Set>: 1 element/chord only appears once)
5. print out onto the console
6. print out onto the hmtl page (textDiv): make use of pre-existing counter (and if the counter is a multiple of 12), then print them out as Green, otherwise, red
*/
function handleTransposeDown() {

  // (Step 1)
  let counter = document.getElementById('myCounter').value;

  counter = parseInt(counter);

  counter--;
  document.getElementById('myCounter').value = counter;

  // (Step 2)
  //initialize arrays
  let resultLyrics = [];
  let resultChords = [];
  let matchesLyric = document.querySelectorAll("#text-area p");
  let matcheschord = document.querySelectorAll("#text-area .chord");
  //  console.log(matches);
  for (var i = 0, l = matchesLyric.length; i < l; i++)
    resultLyrics[i] = matchesLyric[i].innerText;

  for (var i = 0, l = matcheschord.length; i < l; i++)
    resultChords[i] = matcheschord[i].textContent;


  // (Step 3)
  let textDiv = document.getElementById("text-area");

  textDiv.innerHTML = '';



  // (Step 4)
  for (let i = 0; i < resultChords.length; i++) {

    let newChords = [];
    let translatedChords = [];
    let unique = [];

    // (Step 4.1)
    newChords = resultChords[i].split(/\s+/);
    newChords = newChords.filter(Boolean);//remove empty elements from newChords
    for (let x = 0; x < newChords.length; x++) {
      if (!unique.includes(newChords[x])) {
        unique.push(newChords[x]);
      }
    }

    // (Step 4.2) and (Step 4.3)
    let testCount = 0;

    for (let y = 0; y < unique.length; y++) {
      let uniqueY = unique[y];

      // for chords that have a length of >=2
      if (unique[y].length >= 2) {

        // only take the first 2 letters of the chord (and find it)
        let first2C = unique[y].slice(0, 2);

        //check if the first 2 characters of the chord can be found inside the Transpositions (ex: Bb can be found)
        let arrFound = findInTransposition(Transpositions, first2C);

        if(arrFound[0]){

          // check if it equals
          let transpoWithSuffix = getTransposedDown(Transpositions, arrFound[1], arrFound[2], unique[y]);
          translatedChords.push(transpoWithSuffix);
        }

        // (ex: B7 will go here: B7 length >= 2, but B7 is not a chord inside the Transpositions)
        else {
          //check if it includes
          let arrInc = includedInTransposition(Transpositions, first2C);
          if(arrInc[0]){
            let transpoWithSuffix = getTransposedDown(Transpositions, arrInc[1], arrInc[2], unique[y]);
            translatedChords.push(transpoWithSuffix);
          }
        }
      }

      // if the length of the initial chord is 1 (ex: B)
      if (uniqueY.length == 1) {

        let arrInc1= findInTransposition(Transpositions, uniqueY);

        if(arrInc1[0]){

          let transpoWithSuffix = getTransposedDown(Transpositions, arrInc1[1], arrInc1[2], uniqueY);
          translatedChords.push(transpoWithSuffix);
        }
      }
    }//end y-index

    // translate
    let aaaa = '';
    let aa = '';

    for (let w = 0; w < unique.length; w++) {

      let re = new RegExp(`${unique[w]}($|\\s)`, "g");

      if (aa == '') {
        aa = resultChords[i].replace(re, translatedChords[w] + ' ');
      }
      else {
        aaaa = aa.replace(re, translatedChords[w] + ' ');
        aa = aaaa;
      }
    }

    // (Step 5)
    console.log('');
    console.log(aa);
    console.log(resultLyrics[i]);

    // (Step 6)
    if (aa == '') {
      aa = "&nbsp;";
    }
    if (parseInt(document.getElementById("myCounter").value) % 12 == 0) {
      textDiv.innerHTML += `<span class=${'chord'}>${aa}</span>`;
    }
    else{
      textDiv.innerHTML += `<span class=${'chord'} style="color:red">${aa}</span>`;
    }

    aa = ''
    textDiv.innerHTML += `<p> ${resultLyrics[i]}</p>`;

  } //end forloop resultChords[i]
}



/*
new function ---
Name: findInTransposition
Action: (check if the input 'str' is equal to a 'str' element of the 'arr')
1. loop through all elements of the input-parameter-array
2. if the input-parameter-string matches one of the element of the input-parameter-array, then hold a true value, and return the array (will hold a true boolean as arrR[0])
3. else, return the array arrR
*/
function findInTransposition(arr, str) {

  let arrR=[];

  for (let m = 0; m < arr.length; m++) {
    for (let n = 0; n < arr[m].length; n++) {

      if (str == arr[m][n]) {
        arrR.push(true);
        arrR.push(m);
        arrR.push(n);
        return arrR;
        }
      }
    }
  return arrR;
  }

  /*
  new function ---
  Name: findInTransposition
  Action: (check if the input 'str' is included inside a 'str' element of the 'arr')
  1. loop through all elements of the input-parameter-array
  2. if the input-parameter-string is included in one of the element of the input-parameter-array, then hold a true value, and return the array (will hold a true boolean as arrR[0])
  3. else, return the array arrR
  */
function includedInTransposition(arr, str) {

  let arrR=[];

  for (let m = 0; m < arr.length; m++) {
    for (let n = 0; n < arr[m].length; n++) {

      if (str.includes(arr[m][n])) {
        arrR.push(true);
        arrR.push(m);
        arrR.push(n);
        return arrR;
      }
    }
  }
  return arrR;
}


/*
new function ---
Name: getTransposed
Action: apply transpotion (up) just like the assignment stated in a few steps:
1. identity the chord within the transpositions
2. make cases for the suffixes (-m7, -maj, )
*/
function getTransposed(arr, m, n, str) {

  // (Step 1)
  let beforeTranposition = arr[m][n]

  // (Step 2)
  // case for m7 (jump 4 -->)
  if (str.includes('m7')) {
    n = n + 4
    n = ((n) % arr[m].length + arr[m].length) % arr[m].length

  }

  // case for maj (jump 6 <--)
  else if (str.includes('maj')) {
    n = n - 6
    n = ((n) % arr[m].length + arr[m].length) % arr[m].length
  }

  else {
    n++
    n = ((n) % arr[m].length + arr[m].length) % arr[m].length
  }
  let transpoWithSuffix = str.replace(beforeTranposition, arr[m][n])

  return transpoWithSuffix;
}


/*
new function ---
Name: getTransposed
Action: apply transpotion (down) just like the assignment stated in a few steps:
1. identity the chord within the transpositions
2. make cases for the suffixes (-m7, -maj, )
*/
function getTransposedDown(arr, m, n, str) {

  // (Step 1)
  let beforeTranposition = arr[m][n]

  // (Step 2)
  // case for m7 (jump 4 -->)
  if (str.includes('m7')) {
    n = n - 4
    n = ((n) % arr[m].length + arr[m].length) % arr[m].length
  }

  // case for maj (jump 6 <--)
  else if (str.includes('maj')) {
    n = n + 6
    n = ((n) % arr[m].length + arr[m].length) % arr[m].length
  }

  else {
    n--
    n = ((n) % arr[m].length + arr[m].length) % arr[m].length
  }
  let transpoWithSuffix = str.replace(beforeTranposition, arr[m][n])

  return transpoWithSuffix;
}
