# Text Editor in C

In this stage there will be no user interface, the terminal will be used
Should allow select files from an internal folder, once the file was selected is will to load inside an structure and will allow to select where to write or delete new text. The actions performed on the file could be undone, just like `control + z` works.

## Functionalities
- [] Must be able to create a new file
- [] Must be able to select existing files
- [] Must allow writing and deleteingcontent from a file
- [] Must allow undoing actions inside a file
- [] Should keep the actions performed in a file while the file is open; once the file is closed, this history will be deleted

## Analysis 

### Files

Will save:

- Title
- Content

### History of actions 
When a file is open in the application, a history will be created. 
For this structured i going to use a **stack**. Each field of the stack must store an action:

Each action will contain: 

- Type of action
- Data added or deleted
- Position where data was deleted or inserted

### Operations in a file

- Add content: Select a position and insert some text
- Delete content: Select a position and specify the number of characters to delete. The content will be deleted starting from the selected position and moving to the left the specified number of characters.
