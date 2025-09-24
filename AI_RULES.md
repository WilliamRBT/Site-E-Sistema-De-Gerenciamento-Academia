# AI Rules for Gym Landing Page Application

This document outlines the technical stack and specific library usage rules for developing and maintaining the "Gym Landing Page" application. Adhering to these guidelines ensures consistency, maintainability, and leverages the strengths of the chosen technologies.

## Tech Stack Description

*   **Frontend Framework**: React.js for building dynamic and interactive user interfaces.
*   **Language**: TypeScript for enhanced code quality, type safety, and better developer experience.
*   **Styling**: Tailwind CSS for a utility-first approach to rapidly build custom designs and ensure responsiveness.
*   **Build Tool**: Vite for a fast development server and optimized production builds.
*   **Routing**: React Router for declarative navigation and managing application routes.
*   **UI Components**: shadcn/ui for accessible, customizable, and composable UI components.
*   **Icons**: Lucide React for a consistent and extensive set of SVG icons.

## Library Usage Rules

*   **React**: All UI logic should be implemented using React functional components and hooks (`useState`, `useEffect`, `useContext`, etc.).
*   **TypeScript**: All new code files must be written in TypeScript (`.tsx` or `.ts`). Leverage types and interfaces to define data structures and component props.
*   **Tailwind CSS**: Styling should be applied exclusively using Tailwind CSS utility classes. Avoid writing custom CSS in separate files unless absolutely necessary for global styles or complex animations not achievable with Tailwind.
*   **shadcn/ui**: For common UI elements such as buttons, cards, forms, dialogs, etc., prioritize using or adapting components from the shadcn/ui library.
*   **Lucide React**: All icons used throughout the application should be imported and utilized from the `lucide-react` package. Replace any existing custom SVG icons with their Lucide equivalents.
*   **React Router**: Implement all client-side navigation and routing using `react-router-dom`. Define routes in `src/App.tsx`.
*   **State Management**: For local component state, use React's built-in `useState` and `useReducer` hooks. For global state, `useContext` is preferred for simpler scenarios. Avoid external state management libraries unless a clear need arises for complex global state.
*   **File Structure**:
    *   React components should reside in `src/components/`.
    *   Application pages should be placed in `src/pages/`.
    *   Utility functions should be organized in `src/utils/`.
*   **Responsiveness**: All components and layouts must be designed with responsiveness in mind, utilizing Tailwind's responsive prefixes (e.g., `sm:`, `md:`, `lg:`) to ensure optimal display across various screen sizes.