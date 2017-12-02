==============
EMACS COMMANDS
==============


These commands are considering a configuration like the one in:
https://tuhdo.github.io/c-ide.html


Navigating tags
----------------

Run gtags in the root of the project

Go the to the method definition and references::

  M-. -> Go
  M-, -> Go back
  C-j -> When M-. has more than one candidate you quick peek the candidate file with C-j

Speedbar
----------

M-x speedbar -> Opens a window with the directory tree for fast navigation.
SPC -> Navigate in the tree
RET-> Opens the files.

Projectile
-----------

Prefix key of Projectile is C-c p. Some notable features::

  Switch between .h and .c or .cpp: C-c p a.
  Grep in project: C-c p g s
  Multi-occur in project buffers: C-c p o.
  Simple refactoring with text replace in current project: C-c p r.
  Run compilation command at project root: C-c p c. By default, Projectile prompts the make command.


  Jump to any file in the project: C-c p f.
  Jump to any directory in the project: C-c p d.
  List buffers local to current project: C-c p b.
  Jump to recently visited files in project: C-c p e.
  Switch visited projects (visited once an Projectile remembers): C-c p p.


Editing
-----------

M-; or C-c C-c -> Comment/UnComment region M-x comment-region



Refactoring
------------

M-x srefactor-refactor-at-point
