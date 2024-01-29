/*
These functions handle parsing the chord-pro text format
*/


function parseChordProFormat(array) { // chordProLinesArray
  // //parse the song lines with embedded
  // //chord pro chords and add them to DOM
  // console.log('parseChordProFormat::chordProLinesArray')
  // console.dir(chordProLinesArray)
  //
  //
  // //add the lines of text to html <p> elements
  let textDiv = document.getElementById("text-area")
  textDiv.innerHTML = ''

  let chordLine = ''
  let lyricLine = ''

  for (let i = 0; i < array.length; i++) {
    let line = array[i]
    let isReadingChord = false
    chordLine = ''
    lyricLine = ''
    let chordLength = 0 //length of chord symbol

    for (let charIndex = 0; charIndex < line.length; charIndex++) {

      // same thing as another loop that goes through individual char
      for (let ch of line[charIndex]) {
        if (ch === '[') {
          isReadingChord = true
          if(chordLength > 0){
            chordLine += '\xa0' //javascript translate this character into ' '
            chordLength ++
          }
        }
        if (ch === ']') {
          isReadingChord = false
        }
        if (!isReadingChord && ch != ']') {
          lyricLine = lyricLine + ch
          if (chordLength > 0) chordLength-- //consume chord symbol char
          else chordLine = chordLine + '\xa0' //javascript translate this character into ' '
        }
        if (isReadingChord && ch != '[') {
          chordLine = chordLine + ch
          chordLength++
        }
      }

    }

    console.log('')
    console.log(chordLine)
    console.log(lyricLine)

    textDiv.innerHTML += `<span class=${'chord'}>${chordLine}</span>`;
    textDiv.innerHTML += `<p> ${lyricLine}</p>`;
  }

  return chordLine


}
