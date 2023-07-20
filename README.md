<!-- markdownlint-configure-file {
  "MD013": {
    "code_blocks": false,
    "tables": false
  },
  "MD033": false,
  "MD041": false
} -->

[<img src="https://raw.githubusercontent.com/degaur/Oikos-db/patch-1/img/logo.png" align="center" width="100">](https://github.com/zeelsheladiya/OurDB-Database)

# Oikos database

[Oikos-db](https://github.com/zeelsheladiya/OurDB-Database) is an lightweight database, created with c++ for every type of machine. An database scalable, easy to use and portable  which is created and licensed by [Zeel Sheladiya](https://github.com/zeelsheladiya), [Mihir Surati](https://github.com/mihirsurati), [Parth Dabheliya](https://github.com/Parth-Dab), Pranav Patel and contributors.

This is documentation to [Oikos-db](https://github.com/zeelsheladiya/OurDB-Database) which is created and licensed by [Zeel Sheladiya](https://github.com/zeelsheladiya), [Mihir Surati](https://github.com/mihirsurati), [Parth Dabheliya](https://github.com/Parth-Dab), Pranav Patel and contributors too.

## Code of Conduct
Oikos is open for contribution from all people around the world. Whoever your are and whatever your background: nationality, gender, religion, we welcome you. Things to keep in mind:

- Show empathy
- Be patient
- Accept constructive feedback

If you need any help regarding this project feel free to contact us on our [LinkedIn](https://in.linkedin.com/in/zeel-sheladiya-772513176), [GitHub](https://github.com/zeelsheladiya) or [YouTube](https://www.youtube.com/watch?v=2e2Mfs0TdUI) account.

## Contributing
- When you update something or add new module make sure you out comment so others can understand you update or new module
- When you make new syntax make sure to add all syntax varibles in variables/query_variables.h.
- All new query should be dynamic.
- do not commit direct any new update first contact with author than they will test your module and they will commit.
- make sure all error and success message have to registered in Errors/error_variable.h and success_message/Success_Msg.h respectivly.
- do not make static query.
- function should be in globle_functions folder.
- select related query should be in select_module folder.

## Contributions
Oikos-db is open to contributions, but I recommend creating an issue or replying in a comment to let me know what you are working on first that way we don't overwrite each other.

Please read [CONTRIBUTING.md](./CONTRIBUTING.md) and [CODE_OF_CONDUCT.md](./CODE_OF_CONDUCT.md)  for details on this open project. If you have any questions, feel free to open an issue. And feel free to improve this open project by contributing! 

## Contributors
<a href="https://github.com/zeelsheladiya/OurDB/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=zeelsheladiya/OurDB-Database"/>
</a>

---

<!-- markdownlint-configure-file {
  "MD013": {
    "code_blocks": false,
    "tables": false
  },
  "MD033": false,
  "MD041": false
} -->


[<img src="img/logo.png" align="center" width="100">](https://github.com/zeelsheladiya/OurDB-Database) 

# Oikos database

[Oikos-db](https://github.com/zeelsheladiya/OurDB-Database) is an lightweight database, created with c++ for every type of machine. An database scalable, easy to use and licensed under the MIT by [Zeel Sheladiya](https://github.com/zeelsheladiya), [Mihir Surati](https://github.com/mihirsurati), [Parth Dabheliya](https://github.com/Parth-Dab), Pranav Patel and contributors. 

## Table of Contents
- [Scope Of The Project](docs/#scope-of-the-project)
- [Overview Of Existing Systems and Technologies](#scope-of-the-project)
- [Overview Of the Project](#scope-of-the-project)
- [Process flow of Ourdb](#scope-of-the-project)
- [Objectives of Ourdb](#scope-of-the-project)
- [Feasibility](#scope-of-the-project)
- [Consideration](#scope-of-the-project)
- [Getting Started](#getting-started)
- [Syntax and Uses (create database)](#scope-of-the-project)
  - [Select database](#scope-of-the-project)
  - [Create table](#scope-of-the-project)
  - [Current database](#scope-of-the-project)
  - [Rename database](#scope-of-the-project)
  - [Show database](#scope-of-the-project)
  - [Show table](#scope-of-the-project)
  - [Show column in table](#scope-of-the-project)
  - [Rename table in database](#scope-of-the-project)
  - [Rename column in table](#scope-of-the-project)
  - [Insert data into the table](#scope-of-the-project)
  - [Adding new column in to the table](#scope-of-the-project)
  - [Updating a data in to the table](#scope-of-the-project)
  - [Delete the database](#scope-of-the-project)
  - [Delete the table](#scope-of-the-project)
  - [Delete the particular table data](#scope-of-the-project)
  - [Delete the column](#scope-of-the-project)
  - [Select data from table](#scope-of-the-project)
  - [Implementation of database as console GUI](#scope-of-the-project)
  - [Encryption and Decryption](#scope-of-the-project)
  - [How actually data stored in table](#scope-of-the-project)
  - [Future Enhancement](#scope-of-the-project)
- [FAQ](docs/#faq)

## Contributions
Oikos-db is open to contributions, but I recommend creating an issue or replying in a comment to let me know what you are working on first that way we don't overwrite each other.

Please read [CONTRIBUTING.md](./CONTRIBUTING.md) and [CODE_OF_CONDUCT.md](./CODE_OF_CONDUCT.md)  for details on this open project. If you have any questions, feel free to open an issue. And feel free to improve this open project by contributing! 

## Contributors
<a href="https://github.com/zeelsheladiya/OurDB/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=zeelsheladiya/OurDB-Database"/>
</a>
