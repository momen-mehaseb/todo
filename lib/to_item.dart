import 'package:flutter/material.dart';
import 'package:todo/pages/model/model.dart';

class ToDOItem extends StatelessWidget {
  final ToDo toDo;
  final onToDoChanged;
  final onDeletItem;
  const ToDOItem(
      {super.key,
      required this.toDo,
      required this.onToDoChanged,
      required this.onDeletItem});

  @override
  Widget build(BuildContext context) {
    return Container(
        margin: const EdgeInsets.only(bottom: 20),
        child: ListTile(
          onTap: () {
            onToDoChanged(toDo);
          },
          shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(20),
          ),
          contentPadding: const EdgeInsets.symmetric(horizontal: 20, vertical: 5),
          tileColor: Colors.white,
          leading: Icon(
            toDo.isDone ? Icons.check_box : Icons.check_box_outline_blank,
            color: Colors.blue,
          ),
          title: Text(
            toDo.todoText!,
            style: TextStyle(
                fontSize: 16,
                color: Colors.black,
                decoration: toDo.isDone ? TextDecoration.lineThrough : null),
          ),
          trailing: Container(
            height: 35,
            width: 35,
            decoration: BoxDecoration(
                color: Colors.red, borderRadius: BorderRadius.circular(5)),
            child: IconButton(
              color: Colors.white,
              iconSize: 18,
              icon: const Icon(Icons.delete),
              onPressed: () {
                onDeletItem(toDo.id);
              },
            ),
          ),
        ));
  }
}
