const db = require('./db.js');

function insertUser(user) {
    db.connect();
    if (!user || !user.name || !user.email) {
        throw new Error('Invalid user data');
    }
    return db.insert('users', user);
}


console.log('Inserting user...');