#!/usr/bin/node
const request = require('request');
const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}`;

function PrintCharactersInOrder (characters, idx) {
  if (idx >= characters.length) {
    return;
  }
  const characterURL = characters[idx];
  request.get(characterURL, (error, response, body) => {
    if (error) {
      console.log(error);
    }
    if (response.statusCode === 200) {
      console.log(JSON.parse(body).name);
    }
    idx += 1;
    PrintCharactersInOrder(characters, idx);
  });
}
request.get(url, (error, response, body) => {
  if (error) {
    console.log(error);
  } else if (response.statusCode === 200) {
    PrintCharactersInOrder(JSON.parse(body).characters, 0);
  }
});
