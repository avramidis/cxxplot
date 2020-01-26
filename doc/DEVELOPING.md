# Developing cxxplot

To start developing cxxplot your first steps should be to:

1. Compile from source, see [INSTALL.md](INSTALL.md).
2. Run the examples or create your own, see [EXAMPLES.md](EXAMPLES.md)

## cxxplot git development cycle
We use the [git flow](https://guides.github.com/introduction/flow/) workflow. The steps are:

1. Fork the cxxplot repository
2. Add the original cxxplot develop repository as a remote, and check out locally.

    ```bash
    cd cxxplot
    git remote set-url --push origin https://github.com/YOUR_USERNAME/cxxplot
    git remote add upstream https://github.com/avramidis/cxxplot
    git branch develop
    git checkout develop
    git pull --rebase upstream develop
    ```
    
    The steps until here only need to be executed once, with the exception being the last command: rebasing against the development branch.
    You will need to rebase every time when the develop branch is updated.

3. Create a feature branch (from develop)

    ```bash
    git branch feature/BRANCH_NAME
    ```
    
4. In you branch fix bug or add feature. If you add a feature create an example showing this feature.
5. Make sure that locally, your code compiles and and all examples run.    
6. Commit locally, using neat and informative commit messages, grouping commits, potentially iterate over more changes to the code,
7. [Rebase](https://git-scm.com/book/en/v2/Git-Branching-Rebasing) against cxxplot's develop branch.
    This might cause rebase errors, which you need to [solve](https://help.github.com/articles/resolving-merge-conflicts-after-a-git-rebase/)

    ```bash
    git pull --rebase upstream develop
    ```

8. Push your commits to your fork

    ```bash
    git push origin feature/BRANCH_NAME
    ```

    If you squashed or amended commits after you had pushed already, you might be required to force push via using the `git push -f` option with care.

9. Send a pull request via GitHub. As described above, you can always **update** a pull request using the the `git push -f` option. Please **do not** close and send new ones instead, always update.
10. Once the PR is merged, keep an eye on the CI to see whether your patch broke something.

## Requirements for merging your PR
 * All examples must work.
 * The PR is clean and addresses one issue or implements one feature.
 * The number of commits is minimal and the message is neat and clear.