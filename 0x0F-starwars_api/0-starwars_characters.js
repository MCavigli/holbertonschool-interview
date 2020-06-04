#!/usr/bin/node

const request = require('request');

if (process.argv.length === 3) {
  starwars(process.argv[2]);
}

async function starwars (argz) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + argz;
  request(url, async function (err, res, body) {
    if (err) {
      console.log(err);
      return;
    }

    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
      request(characters[i], function (err, res, body) {
        if (err) {
          console.log(err);
          return;
        }
        const name = JSON.parse(body).name;
        console.log(name);
      });
    }
  });
}
